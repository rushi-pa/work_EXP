// PATEL RUSHI DINESH
// ID - 108-189-192
/* Citation and Sources...
Final Project Milestone ?
Module: Menu
Filename: Menu.h
Version 1.0
Author John Doe
Revision History
-----------------------------------------------------------
Date Reason
2020/?/? Preliminary release
2020/?/? Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.

PATEL RUSHI DINESH     108189192
-----------------------------------------------------------*/
#pragma once
#ifndef SDDS_PARKING_H
#define SDDS_PARKING_H
#include<iostream>
#include<ostream>
#include"Menu.h"
#include"Vehicle.h"
#include"Motorcycle.h"
#include"Car.h"
const int MAX_CARS = 100;
using namespace std;
namespace sdds {
	class Parking : public Menu {
	private:
		Vehicle* vehicle[MAX_CARS];
		char* name = nullptr;
		bool LoadData();
		bool ismpty();
		void status();
		bool Exit();
		void Park(int i);
		bool close();
		void list();
		void retuVeh();
		void save();
		void setEmpty();
		int noOfSpots =0 ;
	public:
		void setTitle(const char*);
		Parking(const char*, int spots);
		~Parking();
		int run();
		int count=0;
	};


}
#endif