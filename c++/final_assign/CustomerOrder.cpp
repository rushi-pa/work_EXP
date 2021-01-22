// Name: Rushi
// Seneca Student ID: 108189192
// Seneca email: rdpatel30@myseneca.ca
// Date of completion: 7/10/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.#include <iostream>


#define _CRT_SECURE_NO_WARNINGS

#include "CustomerOrder.h"
using namespace std;

size_t CustomerOrder::m_widthField = 0;

CustomerOrder::CustomerOrder()
{
    m_product = "";
    m_name = "";
    m_cntItem = 0;
    m_lstItem = nullptr;
}
CustomerOrder::CustomerOrder(const std::string& str) {
    size_t Assembly_l = 0;
    Item* LIST[1000];
    bool Spa_left = true;
    Utilities u;
    m_cntItem = 0;
    m_lstItem = nullptr;
    try {
        m_name = u.extractToken(str, Assembly_l, Spa_left);
        m_product = u.extractToken(str, Assembly_l, Spa_left);
        std::string T;
        while (Spa_left) {
            T = u.extractToken(str, Assembly_l, Spa_left);
            LIST[m_cntItem] = new Item(T);
            m_cntItem++;
        }
        m_lstItem = new Item * [m_cntItem];
        for (unsigned int L = 0; L < m_cntItem; L++) {
            m_lstItem[L] = LIST[L];
        }
        m_widthField = max(u.getFieldWidth(), m_widthField);
    }
    catch (string& msg)
    {
        cout << msg;
    }
}


CustomerOrder::~CustomerOrder() {

    }

bool CustomerOrder::isOrderFilled() const {
    bool flag = true;
    for (unsigned int Loop = 0; Loop < m_cntItem; Loop++) {
        {
            if (m_lstItem[Loop]->m_isFilled == false) {
                flag = false;
            }
        }
    };
    return flag;
};

bool CustomerOrder::isItemFilled(const std::string& itemName) const {

    for (unsigned int Loop = 0; Loop < m_cntItem; Loop++) {

        if (m_lstItem[Loop]->m_itemName.compare(itemName) == 0) {  // IF STATMENT

            return m_lstItem[Loop]->m_isFilled;
        }
    }
    return true;
}

void CustomerOrder::fillItem(Station& station, std::ostream& os) {
    for (unsigned int L = 0; L < m_cntItem; L++)
    {
        if (m_lstItem[L]->m_itemName.compare(station.getItemName()) == 0)
        {
            if (station.getQuantity() > 0)
            {
                station.updateQuantity();
                m_lstItem[L]->m_serialNumber = station.getNextSerialNumber();
                m_lstItem[L]->m_isFilled = true;
                os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[L]->m_itemName << "]" << endl;
            }
            else {
                os << "    Unable to fill NAME, PRODUCT " << m_lstItem[L]->m_itemName << endl;
            }
        }
    }
}

void CustomerOrder::display(std::ostream& os) const {
    os << m_name << " - " << m_product << endl;

    for (unsigned int i = 0; i < m_cntItem; i++) {
        os << "[" << setfill('0') << right << setw(6) << m_lstItem[i]->m_serialNumber << "]" << " ";

        os << setfill(' ') << left << setw(m_widthField) << m_lstItem[i]->m_itemName << " - ";
        os << (m_lstItem[i]->m_isFilled ? "FILLED" : "MISSING") << endl;
    }
}