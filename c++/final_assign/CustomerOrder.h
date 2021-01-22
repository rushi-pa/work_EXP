// Name: Rushi
// Seneca Student ID: 108189192
// Seneca email: rdpatel30@myseneca.ca
// Date of completion: 7/10/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.#include <iostream>

#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H
#include "Station.h"
#include "Utilities.h"
#include <iostream>
#include <utility>
#include <cstring>
#include<iomanip>
#include <vector>

using namespace std;

struct Item {
    string m_itemName;
    size_t m_serialNumber = 0;
    bool m_isFilled = false;

    Item(const string& src) : m_itemName(src) {};
};

class CustomerOrder {
private:
    string m_name = "";
    string m_product = "";
    unsigned int m_cntItem = 0;
    Item** m_lstItem;
    static size_t m_widthField;

public:
    CustomerOrder();

    CustomerOrder(const string&);

    CustomerOrder(const CustomerOrder& Assembly_l) {
        throw "NO COPY CONSTRUCTOR ALLOWED!!!";
    };

    CustomerOrder& operator=(CustomerOrder&) = delete;

    CustomerOrder(CustomerOrder&& so) noexcept
    {
        m_name = so.m_name; 
        m_cntItem = so.m_cntItem; 
        m_lstItem = so.m_lstItem;
        m_product = so.m_product;
        so.m_lstItem = nullptr;
    }

    CustomerOrder& operator=(CustomerOrder&& C) noexcept
    {
        if (&C == this)

            return *this;
        if (m_lstItem == nullptr)
        {
        }
        else
        {
            for (unsigned int L = 0; L < m_cntItem; L++) {
                delete m_lstItem[L];
            }
        }

        delete[] m_lstItem;
        m_cntItem = C.m_cntItem;
        m_name = C.m_name;
        m_lstItem = C.m_lstItem;
        m_product = C.m_product;
        return *this;
    }
    ~CustomerOrder();
    bool isOrderFilled() const;
    bool isItemFilled(const string&) const;
    void fillItem(Station&, ostream&);
    void display(ostream&) const;
};
#endif