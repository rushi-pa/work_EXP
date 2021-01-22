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

/*--------------------------------------------------------------------
Description: This header file modularizes general helper functions to
			 help reduce redundant coding for common repetitive tasks.
---------------------------------------------------------------------*/

// HINT: 
// You will most likely want to include this header file
// in other files of the project since it provides general 
// helper functions that can be used throughout.
#include"contacts.h"

//--------------------------------
// Function Prototypes
//--------------------------------

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 4 ======= |
// +-------------------------------------------+

// Clear the standard input buffer
void clearKeyboard(void);

// pause:
// Put function prototype below:
void pause(void);

// getInt:
// Put function prototype below:
int getInt(void);

// getIntInRange:
// Put function prototype below:
int getIntInRange(int MIN, int MAX);

// yes:
// Put function prototype below:
int yes(void);

// menu:
// Put function prototype below:
int menu(void);

// contactManagerSystem:
// Put function prototype below:
void contactManagerSystem(void);

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | NOTE:  Add new function prototypes as per the   |
// |        Milestone-3 specifications document      |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (provided for you)
void getTenDigitPhone(char phoneNum[]);

// findContactIndex (provided for you)
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]);


// displayContactHeader
// put function prototype here:
void displayContactHeader(void);

// displayContactFooter:
// put function prototype here:
void displayContactFooter(int size);

// displayContact:
// put function prototype here:
void displayContact(const struct Contact* contact);

// displayContacts:
// put function prototype here:
void displayContacts(const struct Contact contacts[], int size);

// searchContacts:
// put function prototype here:
void searchContacts(const struct Contact contacts[], int size);

// addContact:
// put function prototype here:
void addContact(struct Contact contacts[], int size);

// updateContact:
// put function prototype here:
void updateContact(struct Contact contacts[], int size);

// deleteContact:
// put function prototype here:
void deleteContact(struct Contact contacts[], int size);
// sortContacts:
// put function prototype here:
void sortContacts(struct Contact contacts[], int size);
