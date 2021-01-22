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
#include "Car.h"
//#include "Utils.h"

#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;
namespace sdds {

	Car::Car():Vehicle() {
		setEmpty();
		Carwash = false;
	}
	Car::Car(const char* a, const char* b) : Vehicle(a, b) {
		setEmpty();
		Carwash = false;
	}

	std::istream& Car::read(std::istream& istr) {
		this->setEmpty();
		if (isCsv()) {
			bool isSide=0;
			Vehicle::read(istr);
			istr>>isSide;
			Carwash = isSide;
			istr.ignore(500, '\n');
		}
		else {
			clear();
			cout << "Car information entry" << endl;
			Vehicle::read(istr);
			cout << "Carwash while parked? (Y)es/(N)o: ";
			char value[10];
			int temp = 0;
			do {
				//clear();
				istr >> value;
				clear();
				if (value[1] == '\0' && (value[0] == 'y' || value[0] == 'Y'))
				{
					Carwash = true;
					temp = 1;
				}
				else {
					if (value[1] == '\0' && (value[0] == 'n' || value[0] == 'N')) {
						Carwash = false;
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
	std::ostream& Car::write(std::ostream& ostr) const {
		if (isEmpty() == true) {
			cout << "Invalid Car object" << endl;
		}
		else {
			if (isCsv()) {
				ostr << "C,";
				Vehicle::write(ostr);
				if (Carwash == true) {
					ostr << "1" << endl;
				}
				else {
					ostr << "0" << endl;
				}
			}
			else {
				ostr << "Vehicle type: Car" << endl;
				Vehicle::write(ostr);
				ostr << endl;
				if (Carwash == true) {
					ostr << "With Carwash";
				}
				else {
					ostr << "Without Carwash";
				}
			}
		}
		return ostr;
	}


	bool Car::int_valid(int value) {
		bool valid = true;
		if (value <= 0) {
			valid = false;
		}
		return valid;
	}


	int Car::getInt(void) {
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
	int Car::getIntInRange(int min, int max) {
		int value;
		bool done = false;
		do {

			value = getInt();
			//clear();
			if (value > max || value < min) {
				printf("Invalid selection, try again: ");
			}
			else {
				done = true;
			}

		} while (!done);

		return value;
	}
	void Car::clear(void) {
		while (getchar() != '\n');
	}
}