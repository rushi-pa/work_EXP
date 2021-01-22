//==============================================
// Name:           Full name here
// Student Number: #########
// Email:          userID@myseneca.ca
// Section:        XXX
// Date:           
//==============================================
// Assignment:     2
// Milestone:      1
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the functions you prototyped
//       in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:

//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+

// clearKeyboard:  Empty function definition 
void clearKeyboard(void)
{
	while (getchar() != '\n');
}

// pause: Empty function definition goes here:
void pause(void) 
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}


// getInt: Empty function definition goes here:
int getInt()
{
	int value;
	char newLine = 'x';
	while (newLine != '\n') {

		scanf("%d%c", &value, &newLine);
		if (newLine != '\n') {
			clearKeyboard();

			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}
	}
	return value;
}


// getIntInRange: Empty function definition goes here:
int getIntInRange(int MIN, int MAX)
{
	int range, Check = 0;
	while (Check == 0) {

		range = getInt();

		if (range > MAX || range < MIN) {
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", MIN, MAX);
		}
		else {
			Check = 1;
		}
	}
	return range;
}


// yes: Empty function definition goes here:
int yes()
{
	char Line = 'x';
	char check = 'x';
	int yes;
    while (Line != '\n') 
	{
		scanf("%c%c", &check, &Line);
		if (Line != '\n') {
			clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		}
		else if (check == 'y' || check == 'Y') {
			yes = 1;
		}
		else if (check == 'n' || check == 'N') {
			yes = 0;
		}
		else {
			Line = 'x';
		}
	}
	return yes;
}
// menu: Empty function definition goes here:
int menu()
{
	int choice = 0;

	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\n");
	printf("Select an option:> ");

	choice = getIntInRange(0, 6);

	return choice;
}

// contactManagerSystem: Empty function definition goes here:
int contactManagerSystem(void)
{
	int done = 0;
	int options;

	while (done == 0) {

		options = menu();

		switch (options) {

		case 1:
			printf("\n<<< Feature 1 is unavailable >>>\n\n");
			pause();
			break;

		case 2:
			printf("\n<<< Feature 2 is unavailable >>>\n\n");
			pause();
			break;

		case 3:
			printf("\n<<< Feature 3 is unavailable >>>\n\n");
			pause();
			break;

		case 4:
			printf("\n<<< Feature 4 is unavailable >>>\n\n");
			pause();
			break;

		case 5:
			printf("\n<<< Feature 5 is unavailable >>>\n\n");
			pause();
			break;

		case 6:
			printf("\n<<< Feature 6 is unavailable >>>\n\n");
			pause();
			break;

		case 0:

			printf("\nExit the program? (Y)es/(N)o: ");
			done = yes();
			break;

		default:
			break;
		}
		printf("\n");
	}
	printf("Contact Management System: terminated\n");
return 0; 
}
