/*
Name:		Kirti Markan
Email:		kmarkan@myseneca.ca
StudentID:	152802187
Date:		12 July, 2020
WorkShop :	6 Part_2

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iostream>
#include "Autoshop.h"
#include "Vehicle.h"

namespace sdds {

	Autoshop& Autoshop::operator +=(Vehicle* theVehicle)
	{
		m_vehicles.push_back(theVehicle); // pushing new vehicle
		return *this; // returning the vector after the new vehicle is added
	}

	void Autoshop::display(std::ostream& out) const
	{
		out << "--------------------------------" << std::endl << "| Cars in the autoshop!        |" << std::endl << "--------------------------------" << std::endl;
		for (auto i = m_vehicles.begin(); i != m_vehicles.end(); ++i)
		{
			(**i).display(out);
			out << std::endl;
		}
		out << "--------------------------------" << std::endl;
	}

	Autoshop::~Autoshop() // Destructor to delete
	{
		auto ptr = m_vehicles.begin();
		for (ptr = m_vehicles.begin(); ptr < m_vehicles.end(); ptr++) // for loop for each and every member
			delete * ptr; // delete each
	}
}