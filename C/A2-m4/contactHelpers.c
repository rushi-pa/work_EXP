//==============================================
// Name:           Patel Rushi Dinesh
// Student Number: 108189192
// Email:          rdpatel30@myseneca.ca
// Section:        NYY
// Date:           26/11/2019
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include"contactHelpers.h"
#include<ctype.h>
#include<limits.h>
#include"contacts.h"
// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

// Include your contactHelpers header file on the next line:
#define MAXCONTACTS 5

//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
// |        function definitions below...            |
// +-------------------------------------------------+

int z =1;
// clearKeyboard:  Empty function definition 
void clearKeyboard(void)
{
	while (getchar() != '\n');
}

// pause: Empty function definition goes here:
void pause(void) 
{
	printf("(Press Enter to Continue)");
        //printf("\n");
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

		if (range > MAX|| range < MIN) {
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
        if(z==1)
{ printf("Contact Management System\n");
z=0;
}else{
	printf("\nContact Management System\n");}
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
void contactManagerSystem(void)
{
	struct Contact contacts[MAXCONTACTS] = {
                      {
			{ "Rick",{ '\0' }, "Grimes" },
			{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
			{ "4161112222", "4162223333", "4163334444" } },
			{
				{ "Maggie", "R.", "Greene" },
				{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
				{ "9051112222", "9052223333", "9053334444" } },
				{
					{ "Morgan", "A.", "Jones" },
					{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
					{ "7051112222", "7052223333", "7053334444" } },
					{
						{ "Sasha",{ '\0' }, "Williams" },
						{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
						{ "9052223333", "9052223333", "9054445555" } },
 };


	int done = 0;
	int options;

	while (done == 0) {

		options = menu();

		switch (options) {


		case 1:
			displayContacts(contacts, MAXCONTACTS);
			pause();
			break;
			printf("\n");

		case 2:
			addContact(contacts, MAXCONTACTS);
			pause();
			break;
			printf("\n");

		case 3:
			updateContact(contacts, MAXCONTACTS);
			pause();
			break;
			printf("\n");

		case 4:
			deleteContact(contacts, MAXCONTACTS);
			pause();
			break;
			printf("\n");

		case 5:
			searchContacts(contacts, MAXCONTACTS);
			pause();
			break;
			printf("\n");

		case 6:
			sortContacts(contacts, MAXCONTACTS);
			pause();
			break;

		case 0:
			printf("\nExit the program? (Y)es/(N)o: ");
			done = yes();
			//printf("\n");
			break;


		default:
			break;
		}
	}
	printf("\nContact Management System: terminated\n");
}
// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10-digit chars entered)
// ---------------------------------------------------------------------------------
// NOTE: Modify this function to validate only numeric character digits are entered
// ---------------------------------------------------------------------------------
void getTenDigitPhone(char *phoneNum)
{
	int needInput = 1;
    int i, digitex, length;

    do {

        digitex = 0;
        scanf("%10s", phoneNum);
        clearKeyboard();

        length = strlen(phoneNum);

        for (i = 0; i < 10 && digitex == 0; i++) {
            if (isdigit(phoneNum[i]) == 0)
                digitex = 1;
        }

        if (length == 10 && digitex == 0) {
            needInput = 0;
        } else {
            printf("Enter a 10-digit phone number: ");
        }

    } while (needInput == 1);

}


// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{

	int j;
	int i = 0;
	int num = -1;
	do {
		j = strcmp(contacts[i].numbers.cell, cellNum);
		if (j == 0) {
			num = i;
		}
		i++;
	} while (i < size);

	return num;
}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void)
{
printf("\n");
printf("+-----------------------------------------------------------------------------+\n");
printf("|                              Contacts Listing                               |\n");
printf("+-----------------------------------------------------------------------------+\n");

}


// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int size) {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", size);
}


// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact* contacts) {
	if (strcmp((*contacts).name.middleInitial, "") == 0)
		printf(" %s %s\n", (*contacts).name.firstName, (*contacts).name.lastName);
	else
		printf(" %s %s %s\n", (*contacts).name.firstName, (*contacts).name.middleInitial, (*contacts).name.lastName);

	printf("    C: %-10s   H: %-10s   B: %-10s\n", (*contacts).numbers.cell, (*contacts).numbers.home, (*contacts).numbers.business);

	if ((*contacts).address.apartmentNumber > 0)
		printf("       %d %s, Apt# %d, %s, %s\n", (*contacts).address.streetNumber, (*contacts).address.street, (*contacts).address.apartmentNumber, (*contacts).address.city, (*contacts).address.postalCode);
	else
		printf("       %d %s, %s, %s\n", (*contacts).address.streetNumber, (*contacts).address.street, (*contacts).address.city, (*contacts).address.postalCode);
}

// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contacts[], int size) {
	int i = 0, j = 0;
	int lenght;
	displayContactHeader();

	for (i = 0; i < size; i++) {
		lenght = strlen(contacts[i].numbers.cell);
		if (lenght > 0) {
			displayContact(&(contacts[i]));
			j++;
		}
	}displayContactFooter(j);
}


// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact contacts[], int size)
{
	int i;
	char cellNum[11];

	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(cellNum);
	i = findContactIndex(contacts, size, cellNum);

	if (i >= 0 && i < size) {
                printf("\n");
		displayContact(&(contacts[i]));

	}
	else printf("*** Contact NOT FOUND ***\n");
	printf("\n");
}

// addContact:
// Put empty function definition below:
void addContact(struct Contact contacts[], int size)
{
	int i, update = -1;

	for (i = 0; i < size; i++)
	{
		if (strlen(contacts[i].numbers.cell) == 0)
		{
			update = i;
			break;
		}
	}
	if (update > -1)
	{
                printf("\n");
		getContact(&contacts[update]);
		printf("--- New contact added! ---\n\n");
	}
	else
	{
		printf("\n*** ERROR: The contact list is full! ***\n");
		printf("\n");
	}
}

// updateContact:
// Put empty function definition below:

void updateContact(struct Contact contact[], int size)
{
	int newup;
	char cellNum[11];

	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(cellNum);

	newup = findContactIndex(contact, size, cellNum);
	if (newup == -1) {
		printf("*** Contact NOT FOUND ***\n\n");
	}
	else {
		printf("\nContact found:\n");
		displayContact(&(contact[newup]));
		//printf("\n");

		printf("\nDo you want to update the name? (y or n): ");
		if (yes() == 1) {
			getName(&(contact[newup].name));
		}
		printf("Do you want to update the address? (y or n): ");
		if (yes() == 1) {
			getAddress(&(contact[newup].address));
		}
		printf("Do you want to update the numbers? (y or n): ");
		if (yes() == 1) {
			getNumbers(&(contact[newup].numbers));
		}
		printf("--- Contact Updated! ---\n\n");
	}
}

// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact contacts[], int size)
{
	int myIndex;
	char cellNum[11];
	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(cellNum);
	//searchContacts(contact, size, cellNum);
	myIndex = findContactIndex(contacts, size, cellNum);

	if (myIndex == -1) {
		printf("*** Contact NOT FOUND ***\n\n");
	}
	else printf("\nContact found:\n");
	displayContact(&(contacts[myIndex]));
	printf("\n");
	printf("CONFIRM: Delete this contact? (y or n): ");
	if (yes() == 1) {
//printf("/n");
		strcpy(contacts[myIndex].numbers.cell, "\0");
		printf("--- Contact deleted! ---\n\n");
	}
        else{
        printf("\n");
}
}

// sortContacts:
// Put empty function definition below
/* */ 
void sortContacts(struct Contact contacts[], int size) {

    int index1, index2;
    struct Contact mid;

    for (index1 = 0; index1 < size; index1++) {
        for (index2 = 0; index2 < size; index2++) {
            if (strcmp(contacts[index1].numbers.cell, contacts[index2].numbers.cell) < 0) {
                mid = contacts[index2];
                contacts[index2] = contacts[index1];
                contacts[index1] = mid;
            }
        }
    }

    printf("\n--- Contacts sorted! ---\n\n");
}
