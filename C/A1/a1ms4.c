//==============================================
// Name:           Rushi Dinesh Patel
// Student Number: 108189192
// Email:          rdpatel30@myseneca.ca
// Section:        NYY
// Date:           11/08/2019
//==============================================
// Assignment:     1
// Milestone:      4
//==============================================


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// #include your contacts header file on the next line:
#include"contacts.h"


int main(void) {
	// Declare variables here:

	 struct Contact contact1[] = {{{{0}}}};

	// Display the title
	printf("Contact Management System\n");
	printf("=========================\n");
	// Contact Name Input:
	getName(contact1);
	// Contact Address Input:
	getAddress(contact1);
	// Contact Numbers Input:
	getNumbers(contact1);

	// Display Contact Summary Details
	printf("\nContact Details\n");
	printf("===============\n");
	printf("Name Details\n");
        printf("------------\n");
	printf("First name: %s\n", contact1[0].Name.firstName);
	printf("Middle initial(s): %s\n", contact1[0].Name.middleInitial);
	printf("Last name: %s\n\n", contact1[0].Name.lastName);
	printf("Address Details\n");
        printf("---------------\n");
	printf("Street number: %d\n", contact1[0].Address.streetNumber);
	printf("Street name: %s\n", contact1[0].Address.street);
	printf("Apartment: %d\n", contact1[0].Address.apartmentNumber);
	printf("Postal code: %s\n", contact1[0].Address.postalcode);
	printf("City: %s\n\n", contact1[0].Address.city);

	printf("Phone Numbers\n");
        printf("-------------\n");
	printf("Cell phone number: %s\n", contact1[0].Numbers.cell);
	printf("Home phone number: %s\n", contact1[0].Numbers.home);
	printf("Business phone number: %s\n", contact1[0].Numbers.business);

	// Display Completion Message
	printf("\nStructure test for Contact using functions done!\n");


	return 0;
}
