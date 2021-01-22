#include <iostream>
#include <iomanip>
#include <vector>
#include "Item.h"
#include"loadCart.h"
using namespace std;
using namespace SDDS;
int FWPrice{ 8 };
int FWDescr{ 15 };

int main(int argc, char* argv[]) {
	cout << setprecision(2) << fixed;
	vector<Item> cart;
	loadCart(argv[1], cart);
	cout << "Items in My Cart:" << endl;
	for (auto& e : cart) {
		e.display(cout);
	}
}