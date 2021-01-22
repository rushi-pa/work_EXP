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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <iomanip>
#include <sstream>
#include <cstring>
#include"Menu.h"
using namespace std;
namespace sdds {
	MenuItem::MenuItem() {
		setEmpty();
		m_item = nullptr;
	}
	MenuItem::MenuItem(const char* name) {
		setEmpty();
		setName(name);
	}
	MenuItem::~MenuItem() {
		delete[] m_item;
		m_item = nullptr;

	}
	void MenuItem::setEmpty() {
		m_item = nullptr;
	}
	void MenuItem::operator=(const MenuItem& mi) const {
		cout << "Cannot assign MenuItem to existing MenuItem." << endl;
	}
	void MenuItem::setName(const char* name) {
		if (name == nullptr) {
			setEmpty();
		}
		else {
			if (isempty() != true) {
				delete[] m_item;
			}
			m_item = new char[strlen(name) + 1];
			int len = strlen(name);
			for (int i = 0; i < len; i++) {
				m_item[i] = name[i];
			}
			m_item[strlen(name)] = '\0';
		};
	}
	std::ostream& MenuItem::display(std::ostream& OS) const {
		for (size_t i = 0; i < strlen(this->m_item); i++) {
			OS << m_item[i];
		}
		//OS << m_item << endl;
		return OS;
	}
	bool MenuItem::isempty() const {
		if (m_item == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}
	Menu::Menu() {
		setEmpty();

	}
	//Menu::Menu(const char* name) {
					//setEmpty();
					//settitle(name);
					//this->intend = 0;
	//}
	Menu::Menu(const char* name, const int intend) {
		setEmpty();
		settitle(name);
		this->intend = intend * 4;
	}
	Menu::~Menu() {
		if (!isempty()) {
			delete[] title;
			title = nullptr;
		}
		for (int i = 0; i < get_size(); i++) {
			if (menu[i] != nullptr) {
				delete menu[i];
				menu[i] = nullptr;
			}
		}
	}
	void Menu::setEmpty() {
		title = nullptr;
		menu[0] = nullptr;
		intend = 0;
		size = 0;
	}
	/*Menu::Menu(const Menu& copy) {
					{
									settitle(copy.title);
									intend = copy.intend;
									if (menu[0] != nullptr) {
													this->menu[0] = nullptr;
													display();
									}
									else {
													for(int i=0;i< this->get_size();i++) { }
													//add(copy.get_item());
									}
					}
	}*/

	void Menu::settitle(const char* name) {
		if (name != nullptr && name[0] != '\0') {
			if (isempty() != true) {
				delete[] title;
			}
			title = nullptr;
			int len = strlen(name);
			title = new char[len + 1];
			for (size_t i = 0; i < strlen(name) + 1; i++) {
				title[i] = name[i];
			}
			title[strlen(name)] = '\0';
		}
		else {
			//delete[] menu;
			setEmpty();
		}
	}

	bool Menu::isempty() const {
		if (title == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}

	std::ostream& Menu::display(std::ostream& OS) const {
		if (isempty() == true) {
			OS << "Invalid Menu!" << endl;
		}
		else {
			addintend();
			//      OS << "**";
			for (size_t i = 0; i < strlen(title); i++) {
				OS << title[i];
			}
			//      OS << "**" << endl;
			OS << endl;
			if (this->get_size() == 0) {
				//      addintend();
				OS << "No Items to display!" << endl;
			}
			else {
				for (int i = 0; i < get_size(); i++) {
					addintend();
					OS << i + 1 << "- ";
					menu[i]->display();
					/*char temp[30];
					strncpy(temp, menu[i]->get_item(),strlen(menu[i]->get_item()));
					temp[strlen(menu[i]->get_item())] = '\0';
					for (size_t j = 0; j < strlen(menu[i]->get_item()); j++) {
									OS << temp[j];
					}*/
					OS << endl;
				}
			}
		}
		return OS;
	}

	void Menu::addintend() const {
		for (int i = 0; i < this->intend; i++) {
			cout << " ";
		}
	}

	/*const {
			   if (isempty() == true) {
							   return false;
			   }
			   else {
							   return true;
			   }
}*/

	void Menu::add(const char* name) {
		if (isempty() == true) {
		}
		else {
			if (get_size() >= MAX_NO_OF_ITEMS) {

			}
			else {
				if (name != nullptr) {
					/*if (menu[0] != nullptr) {
									{
													MenuItem* temp;
													temp = new MenuItem(name);
													//MenuItem(name);
													//for (int i = 0; i < get_size(); i++) {
													//      temp[i].setName(menu[i]->get_item());
																	//temp[i] = menu[i];
													//}
													//temp[get_size()].setName(name);
													//temp[get_size() + 1] = '\0';
													size++;
													menu[get_size()] = temp;
													delete[] menu;
													menu;
													for (int i = 0; i < get_size(); i++) {
																	menu[i]->setName(temp[i].get_item());
																	//menu[i] = temp[i];
													}
													delete[] temp;
													temp = nullptr;
									}
					}
					else {
									//menu = new MenuItem[get_size() + 1];
									MenuItem(name);
									//menu[get_size()]->setName(name);
									size++;
					}*/

					menu[get_size()] = new MenuItem(name);
					/*MenuItem* temp;
					temp = new MenuItem(name);
					menu[get_size()] = temp;
					delete temp;
					//menu[get_size()].MenuItem(name);*/
					size++;
				}
				else {
					setEmpty();
				}
			}
		}
	}

	Menu& Menu::operator<<(const char* name) {
		this->add(name);
		return *this;
	}
	Menu& Menu::operator=(const char* Title) {
		if (Title != nullptr) {
			settitle(Title);
		}
		else
			title = nullptr;

		return *this;
	}
	int Menu::run(std::istream& IS, std::ostream& OS) const {
		int i = 0;
		int final = 0;
		int temp = 0;
		display(OS);

		if (get_size() == 0 || isempty() == true) {

		}
		else {
			addintend();
			cout << "> ";
			do {
				//      addintend();

				IS >> temp;
				if (!IS) {
					OS << "Invalid Integer, try again: ";
					IS.clear();
					IS.ignore(1000, '\n');
				}
				else {
					if (temp <= 0 || temp > get_size()) {
						OS << "Invalid selection, try again: ";
						temp = 0;
						i = 0;
						IS.clear();
						IS.ignore(1000, '\n');
					}
					else {
						cin.clear();
						cin.ignore(1000, '\n');
						final = temp;
						i = 1;

					}
				}
			} while (i == 0);
		}
		return final;
	}

	Menu::operator int() const {
		//int z =run();
		return run();
	}

	Menu& Menu::operator=(const Menu& mi) {
		if (mi.title != nullptr) {
			settitle(mi.title);

			for (int i = 0; i < get_size(); i++)
				if (menu[i] != nullptr)
					delete menu[i];

			if (mi.get_size() > 0)
				for (int i = 0; i < mi.get_size(); i++)
					add(mi.menu[i]->m_item);

			size = mi.get_size();
		}
		else
			setEmpty();
		intend = 8;
		return *this;
	}

	/*Menu& Menu::operator=(const char* title) {
					this->settitle(title);
					return *this;
					}*/

	char* MenuItem::get_item() {
		/*for (int i = 0; i < strlen(this->m_item); i++) {
						cout << m_item[i];
		}
		cout << endl;*/
		return m_item;
	}
	int Menu::get_size() const {
		return this->size;
	}

}