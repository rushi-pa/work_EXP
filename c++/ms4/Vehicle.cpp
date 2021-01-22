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
#include "Vehicle.h"
//#include "Utils.h"

#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;
namespace sdds {

	Vehicle::Vehicle() {
		this->setEmpty();
	}

	Vehicle::Vehicle(const char* plate, const char* model) {
		this->set(plate, model);
	}

	Vehicle::~Vehicle() {
		delete[] m_model;
		m_model = nullptr;
	}

	void Vehicle::set(const char* plate, const char* model) {
		if (str_valid(plate, 0, MAX_PLATE_CHAR) && str_valid(model, 2, MAX_MODEL_CHAR)) {
			parknum = 0;
			strcpy(numplate, plate);
			toUpper(numplate);
			this->setMakeModel(model);
		}
		else {
			this->setEmpty();
		}
	}

	void Vehicle::setEmpty() {
		parknum = -1;
		numplate[0] = '\0';

		if (m_model != nullptr) {
			delete[] m_model;
			m_model = nullptr;
		}
	}

	bool Vehicle::isEmpty() const {
		bool empty = numplate[0] == '\0' || m_model == nullptr || parknum == -1;
		return empty;
	}

	char* Vehicle::getLicensePlate() {
		char* a = numplate;
		return a;
	}

	char* Vehicle::getMakeModel() const {
		return m_model;
	}

	void Vehicle::setMakeModel(const char* model) {
		if (str_valid(model, 2, MAX_MODEL_CHAR)) {
			delete[] m_model;
			m_model = new char[strlen(model) + 1];
			strcpy(m_model, model);
		}
		else {
			this->setEmpty();
		}
	}

	int Vehicle::getParkingSpot() const {
		return parknum;
	}

	void Vehicle::setParkingSpot(int arknum) {
		if (int_valid(arknum)) {
			parknum = arknum;
		}
		else {
			this->setEmpty();
		}
	}

	bool operator==(const Vehicle& lhs, const char* plate) {
		return iequal(lhs.numplate, plate);
	}

	bool operator==(const Vehicle& lhs, const Vehicle& rhs) {
		return iequal(lhs.numplate, rhs.numplate);
	}

	std::istream& Vehicle::read(std::istream& istr = std::cin) {
		if (isCsv()) {
			char plate[9], model[61], spot[10];
			cin.get(spot, 11, ',');
			cin.ignore(2000, ',');
			cin.get(plate, 9, ',');
			cin.ignore(2000, ',');
			cin.get(model, 61, ',');
			cin.ignore(2000, ',');

			parknum = stoi(spot);
			strcpy(numplate, plate);
			toUpper(numplate);
			this->setMakeModel(model);
		}
		else {
			cout << "Enter Licence Plate Number: ";
			strcpy(numplate, getStringInRange(istr, 0, MAX_PLATE_CHAR, "Licence Plate").c_str());
			toUpper(numplate);

			cout << "Enter Make and Model: ";
			this->setMakeModel(getStringInRange(istr, 2, MAX_MODEL_CHAR, "Make and model").c_str());
			parknum = 0;
		}
		if (istr.fail()) {
			this->setEmpty();
		}
		return istr;
	}

	std::ostream& Vehicle::write(std::ostream& ostr = std::cout) const {
		if (!this->isEmpty()) {
			if (isCsv()) {
				ostr << parknum << "," << numplate << "," << m_model << ",";
			}
			else {
				ostr << "Parking Spot Number: ";
				if (parknum == 0) {
					ostr << "N/A";
				}
				else {
					ostr << parknum;
				}
				ostr << endl;
				ostr << "Licence Plate: " << numplate << endl;
				ostr << "Make and Model: " << m_model << endl;
			}
		}
		else {
			ostr << "Invalid Vehicle Object" << endl;
		}

		return ostr;
	}

	std::ostream& operator<<(std::ostream& ostr, const Vehicle& obj) {
		obj.write(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Vehicle& obj) {
		obj.read(istr);
		return istr;
	}

	bool iequal(const char* str1, const char* str2) {
		char* temp1 = nullptr, * temp2 = nullptr;
		bool equal = false;

		if (str_valid(str1,2,61) && str_valid(str2,2,61)) {
			size_t len1 = strlen(str1), len2 = strlen(str2);
			if (len1 == len2) {
				equal = true;
				temp1 = new char[len1 + 1];
				strcpy(temp1, str1);
				temp2 = new char[len2 + 1];
				strcpy(temp2, str2);
				for (size_t i = 0; i < len1 && equal; i++) {
					if (tolower(temp2[i]) != tolower(temp2[i])) {
						equal = false;
					}
				}
				delete[] temp1;
				delete[] temp2;
				temp1 = nullptr;
				temp2 = nullptr;
			}
		}
		return equal;
	}
	void toUpper(char* str){
		if (str != nullptr && str[0] != '\0') {
			for (size_t i = 0; i < strlen(str); i++) {
				str[i] = toupper(str[i]);
			}
		}
	}
	void toLower(char* str) {
		if (str != nullptr && str[0] != '\0') {
			for (size_t i = 0; i < strlen(str); i++) {
				str[i] = tolower(str[i]);
			}
		}
	}
	std::string getStringInRange(std::istream& istr, size_t min, size_t max, const char* msg) {
		std::string value;
		bool done = false;

		do {
			std::getline(istr, value);
			size_t len = value.length();
			if (len != 0 && len <= max && len >= min) {
				done = true;
			}
			else {
				std::cout << "Invalid " << msg << ", try again: ";
			}
		} while (!done);

		return value;
	}

	bool str_valid(const char* tmp, size_t min, size_t max) {
		bool valid = false;
		if (tmp != nullptr && tmp[0] != '\0') {
			size_t len = strlen(tmp);
			if (max == 0 && len != 0) {
				if (len >= min) {
					valid = true;
				}
			}
			else {
				if (len >= min && len <= max) {
					valid = true;
				}
			}
		}
		return valid;
	}

	bool int_valid(int value) {
		bool valid = true;
		if (value <=0) {
			valid = false;
		}
		return valid;
	}


	int getInt(void) {
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
	int getIntInRange(int min, int max) {
		int value;
		bool done = false;
		do {

			value = getInt();
			//clearKeyboard();
			if (value > max || value < min) {
				printf("Invalid selection, try again: ");
			}
			else {
				done = true;
			}

		} while (!done);

		return value;
	}
	void clear(void) {
		while (getchar() != '\n');
	}
}
