/*
Name:		Kirti Markan
Email:		kmarkan@myseneca.ca
StudentID:	152802187
Date:		12 July, 2020
WorkShop :	6 Part_2

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include "Car.h"


using namespace std;
namespace sdds {
	Car::Car(std::istream& is)
	{
		std::string tempdata, tempmaker, tempcondition, tempspeed; 
		std::getline(is, tempdata);
		// For removing , and space
		tempdata.erase(remove(tempdata.begin(), tempdata.end(), '\n'), tempdata.end());
		tempdata.erase(remove(tempdata.begin(), tempdata.end(), '\r'), tempdata.end());

		tempdata.erase(0, tempdata.find(",") + 1);
		tempmaker = tempdata.substr(0, tempdata.find(","));

		tempmaker = tempmaker.substr(tempmaker.find_first_not_of(" "), tempmaker.find_last_not_of(" ") + 1);
		tempmaker = tempmaker.substr(0, tempmaker.find_last_not_of(" ") + 1);

		tempdata.erase(0, tempdata.find(",") + 1);
		tempcondition = tempdata.substr(0, tempdata.find(","));

		tempdata.erase(0, tempdata.find(",") + 1);
		tempspeed = tempdata.substr(0, tempdata.find(","));

		maker = tempmaker;



		if (tempcondition == "" || tempcondition == " ") // if no character and blanks
		{
			car_cond = "n"; // then car is new
		}
		else
		{
			car_cond = tempcondition.substr(tempcondition.find_first_not_of(" "), tempcondition.find_last_not_of(","));
		}
		tempspeed = tempspeed.substr(tempspeed.find_first_not_of(" "));
		// For Invalid records
		std::string err = "Invalid record!";
		if (car_cond != "n" && car_cond != "u" && car_cond != "b") // if token is not n, u, b 
		{
			throw err; // then it is invalid
		}
		try
		{
			TopSpeed = std::stoi(tempspeed); 
		}
		catch (...) // if speed is not a number
		{
			throw err;
		}


	}

	std::string Car::condition() const
	{
		std::string status;
		if (car_cond == "n") // for new car
		{
			status = "new";
		}
		else if (car_cond == "u") // for used car
		{
			status = "used";
		}
		else if (car_cond == "b") // for broken car
		{
			status = "broken";
		}
		return status;
	}

	double Car::topSpeed() const// return top speecd of car
	{
		return TopSpeed;
	}

	void Car::display(std::ostream& out) const // to display in a format
	{
		out << "|" << std::setw(11) << std::right << this->maker << " | " << std::setw(6) << std::left << this->condition() << " | " << std::fixed << std::setprecision(2) << this->topSpeed() << " |";
	}
}