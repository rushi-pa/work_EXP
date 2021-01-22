// Name: Rushi
// Seneca Student ID: 108189192
// Seneca email: rdpatel30@myseneca.ca
// Date of completion: 7/10/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include "Utilities.h"
#include "Station.h"
using namespace std;

size_t Station::size_u = 0;
int Station::index_id = 1;

Station::Station(const std::string& str) {
    id = index_id;
    Utilities utility;
    size_t next_pos = 0;
    bool more = true;
    try {
        name = utility.extractToken(str, next_pos, more);
        series_s = stoi(utility.extractToken(str, next_pos, more));
        present_t = stoi(utility.extractToken(str, next_pos, more));
        size_u = max(utility.getFieldWidth(), size_u);
        desc = utility.extractToken(str, next_pos, more);
    }
    catch (string& msg) {
        cout << msg;
    }
    index_id++;
}

void Station::display(std::ostream& os, bool quantity) const {
    ios init(NULL);
    init.copyfmt(cout);
    os << right;
    os << "[";
    os << setw(3);
    os << setfill('0');
    os << id;
    os << "]";
    os << left;
    os << " Item: ";
    os << setw(size_u);
    os << setfill(' ');
    os << name;
    os << right;
    os << " [";
    os << setw(6);
    os << setfill('0');
    os << series_s;
    os << "]";
    os << left;
    if (quantity == false) {
        os << endl;
    }
    else {
        os << " Quantity: ";
        os << setw(size_u);
        os << setfill(' ');
        os << present_t;
        os << " Description: ";
        os.copyfmt(init);
        os << desc;
        os << endl;
    }
}
const std::string& Station::getItemName() const {
    return name;
}

unsigned int Station::getNextSerialNumber() {
    series_s++;
    return series_s - 1;
}

unsigned int Station::getQuantity() const {
    return present_t;
}

void Station::updateQuantity() {
    present_t--;
    if (present_t < 0) {
        present_t = 0;
    }
}