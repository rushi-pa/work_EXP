/*
Name:		Kirti Markan
Email:		kmarkan@myseneca.ca
StudentID:	152802187
Date:		12 July, 2020
WorkShop :	6 Part_2

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <iostream>
#include <vector>
#include <list>
#include <functional>
#include "Vehicle.h"

namespace sdds {
	class Autoshop {
		std::vector<Vehicle*> m_vehicles; // vector to store all vehicles available
	public:
		Autoshop& operator +=(Vehicle* theVehicle); // add new vehicle to the vector storing all vehicles
		void display(std::ostream& out) const; // display the output
		~Autoshop(); // Destructor

		template <typename T> // template function
		void select(T test, std::list<const Vehicle*>& vehicles)
		{
			for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++)
			{
				if (test(*i) == true) // test a lamba expression that check if it matches prototype
				{
					vehicles.push_back(*i);
				}
			}
		}
	};
}
#endif 