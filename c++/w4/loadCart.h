// Name: Rushi
// Seneca Student ID: 108189192
// Seneca email: rdpatel30@myseneca.ca
// Date of completion: 7/10/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.#include <iostream>
#ifndef SDDS_LOADCART_H
#define SDDS_LOADCART_H
#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include "Item.h"
using namespace std;
namespace SDDS {
    void loadCart(const char* userFile, vector<Item>& cart) {
        ifstream file(userFile);
        if (!file) exit(1);
        while (file) {
            

                string description;
                double price;
                string tax = " ";
                file >> description >> price;
                bool isTaxed = file.get() != '\n';
                if (isTaxed)
                    file >> tax;
                // TODO: create the item in dynamic memory, move it to the cart
                 // and handle any exception
                try {
                Item* p;
                p = new Item(description, price, tax);
                cart.push_back(std::move(*p));
                delete p;
            }
            catch (const char* msg) {
                std::cout << msg;
                std::cout << std::setw(15) << std::left << description;
                std::setprecision(2);
                std::cout << std::setw(8) << std::right << price << "  " << tax << endl;
            }
        } // end while
    }
}

#endif