/*
Name:		Kirti Markan
Email:		kmarkan@myseneca.ca
StudentID:	152802187
Date:		12 July, 2020
WorkShop :	6 Part_2

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/


#include <iostream>
#include <string>
#include "Car.h"



namespace sdds
{
	class Racecar : public Car
	{

		double m_booster = 0.0; // percentage to boost up speed
	public:
		Racecar(std::istream& in); // calls the constructor from car
		void display(std::ostream& out) const; // calls car display function
		double topSpeed() const; // returns top speed of the car
	};
}