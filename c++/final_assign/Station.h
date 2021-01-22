// Name: Rushi
// Seneca Student ID: 108189192
// Seneca email: rdpatel30@myseneca.ca
// Date of completion: 7/10/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.#include <iostream>
#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <iostream>

class Station {
    int id;
    std::string name;
    std::string desc;
    int series_s;
    int present_t;
    static size_t size_u;
    static int index_id;
public:
    Station(const std::string&);
    const std::string& getItemName() const;
    unsigned int getNextSerialNumber();
    unsigned int getQuantity() const;
    void updateQuantity();
    void display(std::ostream& os, bool quantity) const;
};


#endif