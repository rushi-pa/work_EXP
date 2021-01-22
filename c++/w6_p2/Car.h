/*
Name:		Kirti Markan
Email:		kmarkan@myseneca.ca
StudentID:	152802187
Date:		12 July, 2020
WorkShop :	6 Part_2

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <iostream>
#include <fstream>
#include "Vehicle.h"

namespace sdds {

	class Car : public Vehicle {
		std::string maker = { "" }; // name of company that makes the car
		std::string car_cond = { "" }; // condition of the car
		double TopSpeed; // maximum speed of vehicle
	public:
		Car(std::istream&);
		std::string condition() const; // return condition
		virtual double topSpeed() const; // return speed
		virtual void display(std::ostream& out) const; // display the output
	};
}
#endif