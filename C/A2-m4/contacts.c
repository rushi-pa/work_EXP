//==============================================
// Name:           Rushi Dinesh Patel
// Student Number: 108189192
// Email:          rdpatel30@myseneca.ca
// Section:        NYY
// Date:           11/08/2019
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+

#include <string.h>
#include"contacts.h"
#include"contactHelpers.h"

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------
//
void clear()
{
	while (getchar() != '\n');
}
// getName:
// Get and store from standard input the values for Name
// Put your code here that defines the Contact getName function:
void getName(struct Name* name)
{
	int value;
	printf("Please enter the contact's first name: ");
	scanf("%30[^\n]", name->firstName);
	clearKeyboard();
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	value = yes();
	if (value == 1) {
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6[^\n]", name->middleInitial);
		clearKeyboard();
	}else{
         *name->middleInitial='\0';
}
	printf("Please enter the contact's last name: ");
	scanf("%35[^\n]", name->lastName);
	clearKeyboard();

}

// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function:

void getAddress(struct Address* address) {
	int value;
	printf("Please enter the contact's street number: ");
	address->streetNumber = getInt();
	while (address->streetNumber < 0) {
		if (address->streetNumber < 0) {
			printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
			address->streetNumber = getInt();
		}
	}
	printf("Please enter the contact's street name: ");
	scanf(" %40[^\n]", address->street);
	clearKeyboard();
	do {
		printf("Do you want to enter an apartment number? (y or n): ");
		value = yes();
		if (value == 1) {
			printf("Please enter the contact's apartment number: ");
			address->apartmentNumber = getInt();
			while (address->apartmentNumber < 0) {
				if (address->apartmentNumber < 0) {
					printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
					address->apartmentNumber = getInt();
				}
			}
		}
	} while (address->apartmentNumber < 0);
	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]", address->postalCode);
	clearKeyboard();
	printf("Please enter the contact's city: ");
	scanf(" %40[^\n]", address->city);
	clearKeyboard();


}

// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function:
void getNumbers(struct Numbers* numbers) {
	int value;
	printf("Please enter the contact's cell phone number: ");
	//scanf("%10[^\n]", numbers->cell);
	getTenDigitPhone((*numbers).cell);
	printf("Do you want to enter a home phone number? (y or n): ");
	value = yes();
	if (value == 1) {
		printf("Please enter the contact's home phone number: ");
		//scanf("%10[^\n]", numbers->home);
		getTenDigitPhone((*numbers).home);
	}
	else
		strcpy(numbers->home, "\0");
	printf("Do you want to enter a business phone number? (y or n): ");
	value = yes();
	if (value == 1) {
		printf("Please enter the contact's business phone number: ");
		//scanf("%10[^\n]", numbers->business);
		getTenDigitPhone((*numbers).business);
	}
	else {
		strcpy(numbers->business, "\0");
}
	
}


// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 4 ======= |
// +-------------------------------------------+

// getContact:
// Define Empty function definition below:
void getContact(struct Contact* contact)
{
	getName(&(*contact).name);
	getAddress(&(*contact).address);
	getNumbers(&(*contact).numbers);
}
