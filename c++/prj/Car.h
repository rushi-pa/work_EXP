#pragma once
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

#ifndef SDDS_CAR_H__
#define SDDS_CAR_H__
#include "Vehicle.h"

#include <iostream>

namespace sdds {
	class Car : public Vehicle {
		bool Carwash= false;
	public:
		Car();
		Car(const char* a, const char* b);
		Car& operator=(const Car& src) = delete;
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
		void clear(void);
		bool int_valid(int value);
		int getIntInRange(int min, int max);
		int getInt(void);
	};

};
#endif
