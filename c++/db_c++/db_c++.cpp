#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

#include <occi.h>

const int MIN_MAIN{ 0 };		// first option in main menu
const int MAX_MAIN{ 1 };		// last option in main menu
const int CHK_PROD{ 0 };		// option to continue to checkout 
const int ADD_PROD{ 1 };		// option to add another item to cart
const int MAX_CART{ 5 };		// maximum number of products cart can hold

// object representing a shopping cart
struct ShoppingCart
{
	int product_id;
	double price;
	int quantity;

	ShoppingCart() : product_id{ -1 }, price{ 0.0f }, quantity{ 0 }{};
};

// forward declarations (single cpp file allowed for A2 submission)
// helper functions
void displayMainMenu(oracle::occi::Connection* conn);
void clearCart(ShoppingCart cart[], int size);
int promptInt(const std::string err_msg, bool(*invalid_num)(int num));
bool checkoutYesNo();

// A2 required functions
void displayProducts(ShoppingCart cart[], int p_cnt);
int mainMenu();
int customerLogin(oracle::occi::Connection* conn, int cid);
int addToCart(oracle::occi::Connection* conn, struct ShoppingCart cart[]);
int checkout(oracle::occi::Connection* conn, struct ShoppingCart cart[], int cid, int p_cnt);
double findProduct(oracle::occi::Connection* conn, int pid);

int main()
{
	/// OCCI variables
	oracle::occi::Environment* env = nullptr;
	oracle::occi::Connection* conn = nullptr;

	// login variables
	const std::string user{ "dbs311_202b07" };
	const std::string password{ "27889280" };
	const std::string constr{ "myoracle12c.senecacollege.ca:1521/oracle12c" };

	try
	{
		//create environment and connection
		env = oracle::occi::Environment::createEnvironment(oracle::occi::Environment::DEFAULT);
		conn = env->createConnection(user, password, constr);
		
		displayMainMenu(conn);

		// terminate connection
		env->terminateConnection(conn);
		oracle::occi::Environment::terminateEnvironment(env);
	}
	catch (oracle::occi::SQLException& ex)
	{
		std::cout << ex.getErrorCode() << ": " << ex.getMessage();
	}

	return 0;
}

// dislays menu until user decides to exit
void displayMainMenu(oracle::occi::Connection* conn)
{
	int cid;
	ShoppingCart cart[MAX_CART];
	bool running{ true };
	
	while (running)
	{
		switch (mainMenu())
		{
			case 0:
				std::cout << "Good bye!..." << std::endl;
				running = false;
				break;
			case 1:
				std::cout << "Enter the customer ID: ";
				cid = promptInt("Invalid customer ID. ID must be a postive integer: ", [](int num){ return num >= 0;} );
				
				if (customerLogin(conn, cid) < 1)
					std::cout << "Customer does not exist." << std::endl;
				else
					checkout(conn, cart, cid, addToCart(conn, cart));
				break;
			default:
				running = false;
				break;
		}
	}
}

// resets the shopping cart to empty state
void clearCart(ShoppingCart cart[], int size)
{
	for (int i = 0; i < size; ++i)
		cart[i] = ShoppingCart();
}

// prompts user to an integer
// takes in:
//	string, the message that is displayed each time an invalid input is given
//	function pointer, function used to validate integer
int promptInt(const std::string err_msg, bool(*valid_num)(int num))
{
	int in;
	while (!(std::cin >> in) || !valid_num(in))		// check if user input is a number and satisfies condition
	{
		std::cout << err_msg;
		std::cin.clear();														// reset error flag				
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		// clear input buffer (0 - 1):
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return in;
}

// prompts user for Y,y or N,n input
bool checkoutYesNo()
{
	std::string in;
	bool valid;

	do
	{
		std::cout << "Would you like to checkout? (Y/y or N/n): ";
		std::getline(std::cin, in);
		valid = in.length() == 1 && (in[0] == 'y' || in[0] == 'Y' || in[0] == 'n' || in[0] == 'N');
		if (!valid)
			std::cout << "Wrong input. Try again...\n";
	} while (!valid);

	return in[0] == 'y' || in[0] == 'Y';
}

// displays main menu and returns an integer value of the selected menu option
int mainMenu()
{
	std::string msg = "You entered a wrong value. Enter an option (" + std::to_string(MIN_MAIN) + std::string("-") + std::to_string(MAX_MAIN) + std::string("): ");
	std::cout << "*******Main Menu *******\n";
	std::cout << "1)      Login\n";
	std::cout << "0)      Exit\n";
	std::cout << "Enter an option (" << std::to_string(MIN_MAIN) << "-" << std::to_string(MAX_MAIN) << "): ";

	// validate user input
	return promptInt(msg, [](int num){ return (num >= MIN_MAIN && num <= MAX_MAIN); });
}

// searches for a customer given a customer ID
// returns 1 if the customer exists and 0 otherwise
int customerLogin(oracle::occi::Connection* conn, int cid)
{
	int found{ 0 };

	// initialize statement to call procedure
	oracle::occi::Statement* stmt = conn->createStatement();
	stmt->setSQL("BEGIN find_customer(:1,:2); END;");
	stmt->setNumber(1, cid);
	stmt->registerOutParam(2, oracle::occi::Type::OCCIINT, sizeof(int));
	
	try
	{
		stmt->execute();
		found = stmt->getInt(2);
	}
	catch (oracle::occi::SQLException& err)
	{
		std::cout << err.getErrorCode() << ": " << err.getMessage();
	}

	conn->terminateStatement(stmt);
	return found;
}

// prompts user to add products to their shopping cart
// users can then continue to add products until the cart is full
// or checkout immediately
int addToCart(oracle::occi::Connection* conn, struct ShoppingCart cart[])
{		
	int pid, in{ 1 }, num_items{ 0 };
	double price{ 0.0f };

	std::cout << "-------------- Add Products to Cart --------------" << std::endl;

	while (num_items < MAX_CART && in == ADD_PROD)
	{
		// prompt for valid product ID
		std::cout << "Enter the product ID: ";
		pid = promptInt("Invalid product ID. ID must be a positive integer: ", [](int num){ return num > 0; });
		price = findProduct(conn, pid);

		if (price <= 0)
			std::cout << "The product does not exist. Try again..." << std::endl;
		else
		{
			// add the product to the cart
			// prompt user to enter the quantity for the product
			cart[num_items].product_id = pid;
			cart[num_items].price = price;

			std::cout << "Product Price: " << std::setiosflags(std::ios::fixed) << std::setprecision(2) << price << std::endl;
			std::cout << std::resetiosflags(std::ios::fixed) << "Enter the product quantity: ";
			cart[num_items].quantity = promptInt("Invalid quantity (minimum 1): ", [](int num){ return num >= 1; });
			++num_items;

			// check if the cart is full
			if (num_items >= MAX_CART)
				std::cout << "Shopping Cart Full. Proceeding to checkout" << std::endl;
			else
			{
				// prompt user to add more products or checkout
				std::cout << "Enter " << ADD_PROD << " to add more products or " << CHK_PROD << " to checkout: ";
				in = promptInt("Invalid choice. Please enter " + std::to_string(ADD_PROD) + " or " + std::to_string(CHK_PROD) + ": ",
					[](int num){ return num == ADD_PROD || num == CHK_PROD;});
			}
		}
	}

	displayProducts(cart, num_items);
	return num_items;
}

// searches for a product given a product ID
// returns 0 if the ID is invalid and a non-zero price if it is valid
double findProduct(oracle::occi::Connection* conn, int pid)
{
	double price{ 0.0f };

	// call find_order procedure
	oracle::occi::Statement* stmt = conn->createStatement();
	stmt->setSQL("BEGIN find_product(:1,:2); END;");
	stmt->setNumber(1, pid);
	stmt->registerOutParam(2, oracle::occi::Type::OCCIDOUBLE, sizeof(double));

	try
	{
		stmt->execute();				
		price = stmt->getDouble(2);
	}
	catch (oracle::occi::SQLException& err)
	{
		std::cout << err.getErrorCode() << ": " << err.getMessage();
	}

	conn->terminateStatement(stmt);
	return price;
}

// displays all the items inside of the shopping cart
void displayProducts(struct ShoppingCart cart[], int p_cnt)
{
	double total{ 0.0f };

	std::cout << "------- Ordered Products ---------\n";
	for (int i = 0; i < p_cnt; ++i)
	{
		std::cout << "---Item " << i + 1;
		std::cout << "\nProduct ID: " << cart[i].product_id;
		std::cout << "\nPrice: " << std::setiosflags(std::ios::fixed) << std::setprecision(2) << cart[i].price; 
		std::cout << "\nQuantity: " << std::resetiosflags(std::ios::fixed) << cart[i].quantity << std::endl;
		total += cart[i].price * cart[i].quantity;
	}

	std::cout << "----------------------------------\nTotal: " << std::setiosflags(std::ios::fixed) << std::setprecision(2) << total << std::resetiosflags(std::ios::fixed) << std::endl;
}

// checkout all items in the current shopping cart
// order and its order items are stored into the database
int checkout(oracle::occi::Connection* conn, ShoppingCart cart[], int cid, int p_cnt)
{
	int oid;
	if (!checkoutYesNo())
		std::cout << "The order is cancelled." << std::endl;
	else
	{
		// call add_order procedure
		oracle::occi::Statement* stmt = conn->createStatement();
		stmt->setSQL("BEGIN add_order(:1,:2); END;");
		stmt->setNumber(1, cid);
		stmt->registerOutParam(2, oracle::occi::Type::OCCIINT, sizeof(int));

		try
		{
			stmt->execute();
			oid = stmt->getInt(2);

			// call add_order_item procedure
			stmt->setSQL("BEGIN add_order_item(:1,:2,:3,:4,:5); END;");
			for (int i = 0; i < p_cnt; ++i)
			{
				// set arguments for the order
				stmt->setNumber(1, oid);
				stmt->setNumber(2, i + 1);
				stmt->setNumber(3, cart[i].product_id);
				stmt->setNumber(4, cart[i].quantity);
				stmt->setNumber(5, cart[i].price);

				stmt->execute();
				conn->terminateStatement(stmt);
			}
		}
		catch (oracle::occi::SQLException& err)
		{
			std::cout << err.getErrorCode() << ": " << err.getMessage();
		}

		std::cout << "The order is successfully completed." << std::endl;
	}

	clearCart(cart, p_cnt);
	return 0;
}