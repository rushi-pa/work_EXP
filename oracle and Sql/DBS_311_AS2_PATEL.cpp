#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <occi.h>


const int add_pro{ 1 };
const int size_cart{ 5 };
const int mini_m{ 0 };
const int max_m{ 1 };
const int auc_pro{ 0 };

struct ShoppingCart
{
	int product_id;
	double price;
	int quantity;
	ShoppingCart() : product_id{ -1 }, price{ 0.0f }, quantity{ 0 }{};
};


void displayMainMenu(oracle::occi::Connection* conn);
void clearCart(ShoppingCart cart[], int size);
int promptInt(const std::string err_msg, bool(*invalid_num)(int num));
bool checkoutYesNo();
void displayProducts(ShoppingCart cart[], int p_cnt);
int mainMenu();
int customerLogin(oracle::occi::Connection* conn, int cid);
int addToCart(oracle::occi::Connection* conn, struct ShoppingCart cart[]);
int checkout(oracle::occi::Connection* conn, struct ShoppingCart cart[], int cid, int p_cnt);
double findProduct(oracle::occi::Connection* conn, int pid);

int main()
{
	oracle::occi::Environment* env = nullptr;
	oracle::occi::Connection* conn = nullptr;

	const std::string user{ "dbs311_202d21" };
	const std::string password{ "Varu@1004" };
	const std::string constr{ "myoracle12c.senecacollege.ca:1521/oracle12c" };

	try
	{
		env = oracle::occi::Environment::createEnvironment(oracle::occi::Environment::DEFAULT);
		conn = env->createConnection(user, password, constr);

		displayMainMenu(conn);
		env->terminateConnection(conn);
		oracle::occi::Environment::terminateEnvironment(env);
	}
	catch (oracle::occi::SQLException& ex)
	{
		std::cout << ex.getErrorCode() << ": " << ex.getMessage();
	}

	return 0;
}
void displayMainMenu(oracle::occi::Connection* conn)
{
	int cid;
	ShoppingCart cart[size_cart];
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
			cid = promptInt("Invalid customer ID. ID must be a postive integer: ", [](int num) { return num >= 0; });

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
void clearCart(ShoppingCart cart[], int size)
{
	for (int i = 0; i < size; ++i)
		cart[i] = ShoppingCart();
}
int promptInt(const std::string err_msg, bool(*valid_num)(int num))
{
	int in;
	while (!(std::cin >> in) || !valid_num(in))	
	{
		std::cout << err_msg;
		std::cin.clear();													
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return in;
}
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
int mainMenu()
{
	std::string msg = "You entered a wrong value. Enter an option (" + std::to_string(mini_m) + std::string("-") + std::to_string(max_m) + std::string("): ");
	std::cout << "*******Main Menu *******\n";
	std::cout << "1)      Login\n";
	std::cout << "0)      Exit\n";
	std::cout << "Enter an option (" << std::to_string(mini_m) << "-" << std::to_string(max_m) << "): ";

	return promptInt(msg, [](int num) { return (num >= mini_m && num <= max_m); });
}
int customerLogin(oracle::occi::Connection* conn, int cid)
{
	int found{ 0 };
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
int addToCart(oracle::occi::Connection* conn, struct ShoppingCart cart[])
{
	int pid, in{ 1 }, num_items{ 0 };
	double price{ 0.0f };

	std::cout << "-------------- Add Products to Cart --------------" << std::endl;

	while (num_items < size_cart&& in == add_pro)
	{
		std::cout << "Enter the product ID: ";
		pid = promptInt("Invalid product ID. ID must be a positive integer: ", [](int num) { return num > 0; });
		price = findProduct(conn, pid);

		if (price <= 0)
			std::cout << "The product does not exist. Try again..." << std::endl;
		else
		{
			cart[num_items].product_id = pid;
			cart[num_items].price = price;

			std::cout << "Product Price: " << std::setiosflags(std::ios::fixed) << std::setprecision(2) << price << std::endl;
			std::cout << std::resetiosflags(std::ios::fixed) << "Enter the product quantity: ";
			cart[num_items].quantity = promptInt("Invalid quantity (minimum 1): ", [](int num) { return num >= 1; });
			++num_items;
			if (num_items >= size_cart)
				std::cout << "Shopping Cart Full. Proceeding to checkout" << std::endl;
			else
			{
				std::cout << "Enter " << add_pro << " to add more products or " << auc_pro << " to checkout: ";
				in = promptInt("Invalid choice. Please enter " + std::to_string(add_pro) + " or " + std::to_string(auc_pro) + ": ",
					[](int num) { return num == add_pro || num == auc_pro; });
			}
		}
	}

	displayProducts(cart, num_items);
	return num_items;
}
double findProduct(oracle::occi::Connection* conn, int pid)
{
	double price{ 0.0f };
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
int checkout(oracle::occi::Connection* conn, ShoppingCart cart[], int cid, int p_cnt)
{
	int oid;
	if (!checkoutYesNo())
		std::cout << "The order is cancelled." << std::endl;
	else
		oracle::occi::Statement* stmt = conn->createStatement();
		stmt->setSQL("BEGIN add_order(:1,:2); END;");
		stmt->setNumber(1, cid);
		stmt->registerOutParam(2, oracle::occi::Type::OCCIINT, sizeof(int));

		try
		{
			stmt->execute();
			oid = stmt->getInt(2);
			stmt->setSQL("BEGIN add_order_item(:1,:2,:3,:4,:5); END;");
			for (int i = 0; i < p_cnt; ++i)
			{
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