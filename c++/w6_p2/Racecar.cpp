/*
Name:		Kirti Markan
Email:		kmarkan@myseneca.ca
StudentID:	152802187
Date:		12 July, 2020
WorkShop :	6 Part_2

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include "Car.h"
#include "Racecar.h"


namespace sdds
{
	Racecar::Racecar(std::istream& in) :Car(in) // :constructor from car
	{// TAG,MAKER,CONDITION,TOP_SPEED,BOOSTER
		
		std::string inputformat;

		for (int i = 0; i < 5; i++)
		{
			in.unget(); // extracting last field from stream
		}


		// For input format
		std::getline(in, inputformat);

		// erase every , 
		inputformat.erase(0, inputformat.find(",") + 1);

		inputformat.erase(remove(inputformat.begin(), inputformat.end(), '\n'), inputformat.end());
		inputformat.erase(remove(inputformat.begin(), inputformat.end(), '\r'), inputformat.end());

		m_booster = std::stod(inputformat); // puting the new format
	}



	double Racecar::topSpeed() const
	{
		return Car::topSpeed()* (1 + m_booster); // returning top speed of car 
		//1 + m_booster for any booster effects
	}

	void Racecar::display(std::ostream & out) const
	{
		// format will be | MAKER | CONDITION | TOP_SPEED |*
		Car::display(out); // print information about car
		out << "*"; // add * at end
	}
}