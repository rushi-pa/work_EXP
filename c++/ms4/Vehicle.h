/* Citation and Sources...
Final Project Milestone 4
Module: Vehicle
Filename: Vehicle.h
Date 27.03.2020
Reason ms4 
RUSHI DINESH PATEL
108189192
-----------------------------------------------------------
Date 27.03.2020
Reason
2020/?/? Preliminary release
2020/?/? Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_VEHICLE_H__
#define SDDS_VEHICLE_H__
#include "ReadWritable.h"

#include <iostream>

namespace sdds {

	const int MAX_PLATE_CHAR = 8;
	const int MAX_MODEL_CHAR = 60;

	class Vehicle : public ReadWritable {
		char numplate[MAX_PLATE_CHAR + 1];
		char* m_model = nullptr;
		int parknum;

	protected:
		void set(const char* plate, const char* model);
		void setEmpty();
		bool isEmpty() const;
		char* getLicensePlate();
		char* getMakeModel() const;
		void setMakeModel(const char* model);

	public:
		Vehicle();
		Vehicle(const char* plate, const char* model);
		~Vehicle();
		int getParkingSpot() const;
		void setParkingSpot(int parknum);
		friend bool operator==(const Vehicle& lhs, const char* plate);
		friend bool operator==(const Vehicle& lhs, const Vehicle& rhs);
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
		Vehicle(const Vehicle& src) = delete;
		Vehicle& operator=(const Vehicle& src) = delete;
	};
	std::ostream& operator<<(std::ostream& ostr, const Vehicle& obj);
	std::istream& operator>>(std::istream& istr, Vehicle& obj);
	bool iequal(const char* str1, const char* str2);
	void clear(void);
	bool str_valid(const char* tmp, size_t min, size_t max);
	void toUpper(char* str);
	void toLower(char* str);
	bool int_valid(int value);
	bool int_valid(int value);
	std::string getStringInRange(std::istream& istr, size_t min, size_t max, const char* msg);
}

#endif
