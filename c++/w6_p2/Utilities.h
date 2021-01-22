/*
Name:		Kirti Markan
Email:		kmarkan@myseneca.ca
StudentID:	152802187
Date:		12 July, 2020
WorkShop :	6 Part_2

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include <iostream>
#include <sstream>
#include "Vehicle.h"
#include "Car.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in);
}
#endif 