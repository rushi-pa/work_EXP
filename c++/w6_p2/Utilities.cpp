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
#include <iomanip>
#include "Utilities.h"
#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"

using namespace std;
namespace sdds {
	Vehicle* createInstance(std::istream& in)
	{
		char c = '\0';
		Vehicle* ptr = nullptr; // assigning ptr nullptr
		do
		{
			in.get(c);
		} while (c == ' ' || c == ',');
		if (c == 'c' || c == 'C')
		{
			Car* x = new Car(in); // create instance of car
			ptr = x;
		}
		else if (c == 'r' || c == 'R')
		{
			Car* x = new Racecar(in); // create instance of Racecar
			ptr = x;
		}
		else if (c != '\0' && c != ' ' && c != ',' && c != '\n' && isalpha(c)) // if the character is not c, C, r, or R
		{ // then it is a exception
			// ptr remain null =ptr
			in.ignore(1000, '\n');
			throw c;
		}
		return ptr;
	}
}