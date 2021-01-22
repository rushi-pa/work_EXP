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

//clear function decleration
void clear() {
              while (getchar() != '\n');
}

// Get and store from standard input the values for Name
// Put your code here that defines the Contact getName function:
void getName(struct Contact* Name)
{
	char value;
	printf("Please enter the contact's first name: ");
	scanf(" %30[^\n]",Name->Name.firstName);
	clear();

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf(" %c", &value);
	clear();
	if (value == 'y' || value == 'Y')
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %6[^\n]", Name->Name.middleInitial);
		clear();
	}
	printf("Please enter the contact's last name: ");
	scanf(" %35[^\n]", Name->Name.lastName);
	clear();

}

// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function:

void getAddress(struct Contact* contact) {
	char middle;
	printf("Please enter the contact's street number: ");
	scanf(" %d", &contact->Address.streetNumber);
	clear();

	printf("Please enter the contact's street name: ");
	scanf(" %36[^\n]", contact->Address.street);
	clear();

	printf("Do you want to enter an apartment number? (y or n): ");
	scanf(" %c", &middle);
	clear();

	if (middle == 'y' || middle == 'Y') {

		printf("Please enter the contact's apartment number: ");
		scanf(" %d", &contact->Address.apartmentNumber);
		clear();
	}

	printf("Please enter the contact's postal code: ");
	scanf(" %8[^\n]", contact->Address.postalcode);
	clear();

	printf("Please enter the contact's city: ");
	scanf(" %40[^\n]", contact->Address.city);
	clear();

}

// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function:
void getNumbers(struct Contact* contact) {
	char value;
	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf(" %c", &value);
	clear();
	if (value == 'y' || value == 'Y') {
		printf("Please enter the contact's cell phone number: ");
		scanf(" %20[^\n]", contact->Numbers.cell);
            // if(contact->Numbers.cell == 0)
//{ printf("INVALID ENTRY");}//
		clear();
	}

	printf("Do you want to enter a home phone number? (y or n): ");
	scanf(" %c", &value);
	clear();
	if (value == 'y' || value == 'Y') {
		printf("Please enter the contact's home phone number: ");
		scanf(" %20[^\n]", contact->Numbers.home);
		clear();
	}
	printf("Do you want to enter a business phone number? (y or n): ");
	scanf(" %c", &value);
	clear();
	if (value == 'y' || value == 'Y') {
		printf("Please enter the contact's business phone number: ");
		scanf(" %20[^\n]", contact->Numbers.business);
		clear();
	
}
}
/*
 * //function which validates entered integer
int check(const char* a)
{
int done=0;
int one;
int value;
char after;
do
{
frst=scanf("%d %c", &value, &after);
if(frst==0)
{
printf(enter the contacts %s: ",a);
clear();
}
else
if(after!='\n')
{
printf("Please enter the contacts %s: ",a);
clear();
}
else
if(value> INT_MAX || VALUE<0)
{
printf("Please enter the contacts %s: ", a);
}
else
{done=1;
}
}while(done!=1);
return value;
}*/
