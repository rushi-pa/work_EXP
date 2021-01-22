/* Citation and Sources...
Final Project Milestone 4
Module: Vehicle
Filename: Vehicle.cpp
Version 1.
Revision History
-----------------------------------------------------------
Date 27.03.2020
Reason ms4 RUSHI DINESH PATEL
108189192
2020/?/? Preliminary release
2020/?/? Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include "Motorcycle.h"
//#include "Utils.h"

#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;
namespace sdds {

	Motorcycle::Motorcycle() {
		setEmpty();
		hasSide = false;
	}
	Motorcycle::Motorcycle(const char* a, const char* b) : Vehicle(a, b) {
		setEmpty();
		hasSide = false;
	}

	std::istream& Motorcycle::read(std::istream& istr) {
		if (isCsv()) {
			bool isSide = 0;
			Vehicle::read(istr);
			istr >> isSide;
			hasSide = isSide;
			istr.ignore(500, '\n');
		}
		else {

			clear();
			cout << "Motorcycle information entry" << endl;
			Vehicle::read(istr);
			cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
			char value[10];
			int temp = 0;
			do {
				//clear();
				istr >> value;
				clear();
				if (value[1] == '\0' && (value[0] == 'y' || value[0] == 'Y'))
				{
					hasSide = true;
					temp = 1;
				}
				else {
					if (value[1] == '\0' && (value[0] == 'n' || value[0] == 'N')) {
						hasSide = false;
						temp = 1;
					}
					else {
						cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
						temp = 0;
						value[0] = '\0';
					}
				}
			} while (temp == 0);
		}
		//if (istr.fail()) {
		//	this->setEmpty();
		//}
		return istr;
	}
	std::ostream& Motorcycle::write(std::ostream& ostr) const {
		if (isEmpty() == true) {
			cout << "Invalid Motorcycle Object" << endl;
		}
		else {
			if (isCsv()) {
				ostr << "M,";
				Vehicle::write(ostr);
				if (hasSide == true) {
					ostr << "1" << endl;
				}
				else {
					ostr << "0" << endl;
				}
			}
			else {
				ostr << "Vehicle type: Motorcycle" << endl;
				Vehicle::write(ostr);
				
				if (hasSide == true) {
					ostr << endl;
					ostr << "With Sidecar";
				}
				/*else {
					ostr << "Without SideCar" << endl;
				}*/
			}
		}
		return ostr;
	}

	bool Motorcycle::int_valid(int value) {
		bool valid = true;
		if (value <= 0) {
			valid = false;
		}
		return valid;
	}


	int Motorcycle::getInt(void) {
		bool flag = false;
		int frst;
		int value;
		char after;
		do {
			frst = scanf("%d%c", &value, &after);
			if (frst == 0) {
				printf("Invalid Integer, try again: ");
				clear();
			}
			else if (after != '\n') {
				printf("Invalid Integer, try again: ");
				clear();
			}
			else {
				flag = true;
			}

		} while (!flag);

		return value;
	}
	int Motorcycle::getIntInRange(int min, int max) {
		int value;
		bool done = false;
		do {

			value = getInt();
			clear();
			if (value > max || value < min) {
				printf("Invalid selection, try again: ");
			}
			else {
				done = true;
			}

		} while (!done);

		return value;
	}
	void Motorcycle::clear(void) {
		while (getchar() != '\n');
	}
}
