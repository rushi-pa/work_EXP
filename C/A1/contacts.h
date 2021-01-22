
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

// Structure type Name declaration
//structure declared for assigning names
struct Name {
	char firstName[31];
	char middleInitial[7];
	char lastName[36];
};
// Strucuture type address declaration
// Structure declared for assigning addredd info
struct Address {
	int streetNumber;
	char street[41];
	int apartmentNumber;
	char postalcode[8];
	char city[41];
};
// Structure Numbers is defined to assign phone numbers in it

struct Numbers {
	char cell[11];
	char home[11];
	char business[11];
};
//defining our own datatype
struct Contact {
	struct Name Name;
	struct Address Address;
	struct Numbers Numbers;
};
// clear function declaration
//void clear() {
//	while (getchar() != '\n');
//}//
//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------
void getName(struct Contact*);

void getAddress(struct Contact*);

void getNumbers(struct Contact*);
