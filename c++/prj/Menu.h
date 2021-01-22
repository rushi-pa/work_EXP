#pragma once
#pragma once
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
#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include<iostream>
#include<ostream>
const int MAX_NO_OF_ITEMS = 10;
using namespace std;
namespace sdds
{
	class Menu;
	class MenuItem {
		friend class Menu;
	private:
		char* m_item = nullptr;
	public:
		MenuItem();
		MenuItem(const char*);
		~MenuItem();
		void setEmpty();
		void operator=(const MenuItem& mi) const;
		MenuItem(const MenuItem&) = delete;
		void setName(const char* name);
		std::ostream& display(std::ostream & = cout) const;
		char* get_item();
		bool isempty() const;

	};
	class Menu {
	private:
		char* title = nullptr;
		MenuItem* menu[MAX_NO_OF_ITEMS];
		int intend = 0;
		int size = 0;
	public:
		Menu();
		//Menu(const char*);
		Menu(const char*, const int = 0);
		~Menu();
		void setEmpty();
		//Menu(const Menu&);
		void settitle(const char* name);
		bool isempty() const;
		std::ostream& display(std::ostream & = cout) const;
		//bool operator()(const Menu&) const;
		operator bool() const {
			return !isempty();
		}
		void add(const char*);
		Menu& operator<<(const char*);
		int run(std::istream & = cin, std::ostream & = cout) const;
		//int operator=(Menu&);
		Menu& operator=(const char*);
		int get_size() const;
		void addintend() const;
		Menu& operator=(const Menu& mi);
		//Menu& operator=(const char*);
		operator int() const;
	};

};

#endif