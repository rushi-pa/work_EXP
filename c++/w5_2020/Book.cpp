// Ruhsi Patel
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
#include<sstream>
#include<cstring>
#include<iomanip>
#include <string>
#include"Book.h"
using namespace std;
namespace sdds {
    Book::Book() {

        B_DESC = "";
        B_PRICE = 0.0;
        B_YEAR = 0;
        B_COUNTRY = "";
        B_TITLE = "";
        B_AUTHOR = "";
    }

    const size_t& Book::year() const
    {
        return B_YEAR;
    }

    double& Book::price()
    {
        return B_PRICE;    
    }

    const string& Book::country() const
    {
        return B_COUNTRY;
    }

    const string& Book::title() const
    {
        return B_TITLE; 
    }
    void Book::setPrice(double input) {
        B_PRICE = input;
    }

    Book::Book(const string& res)
    {
        string tempo = res;
        size_t found = 0;
        string copy;
        string temp;
        /*do {
            found = tempo.find(' ');
            if (found != std::string::npos)
                tempo.erase(std::find(tempo.begin(), tempo.end(), ' '));
        } while (found != std::string::npos);*/
        char c;
        found = tempo.find(',');
        c = tempo[found - 1];
        if (c == ' ') {
            do {
                tempo.erase(found, 1);
                found--;
                c = tempo[found - 1];

            } while (c == ' ');
        }
        copy = tempo.substr(0, found);
        B_AUTHOR = copy;
        tempo = tempo.substr(found + 1);
       
        c = tempo[0];
        if (c == ' ') {
            do {
                tempo.erase(std::find(tempo.begin(), tempo.end(), ' '));
                c = tempo[0];
            } while (c == ' ' || c== '\0');
        }
        
        found = tempo.find(',');
        c = tempo[found - 1];
        if (c == ' ') {
            do {
                tempo.erase(found , 1);
                found--;
                c = tempo[found - 1];
               
            } while (c == ' ');
        }
        copy = tempo.substr(0, found);
        B_TITLE = copy;
        tempo = tempo.substr(found + 1);
        c = tempo[0];
        if (c == ' ') {
            do {
                tempo.erase(std::find(tempo.begin(), tempo.end(), ' '));
                c = tempo[0];
            } while (c == ' ');
        }
        
        found = tempo.find(',');
        c = tempo[found - 1];
        if (c == ' ') {
            do {
                tempo.erase(found, 1);
                found--;
                c = tempo[found - 1];

            } while (c == ' ');
        }
        c = tempo[found -1];
        if (c == ' ') {
            do {
                tempo.erase(std::find(tempo.begin(), tempo.end(), ' '));
                c = tempo[found-1];
            } while (c == ' ');
        }
        copy = tempo.substr(0, found);
        B_COUNTRY = copy;

        tempo = tempo.substr(found + 1);
        c = tempo[0];
        if (c == ' ') {
            do {
                tempo.erase(std::find(tempo.begin(), tempo.end(), ' '));
                c = tempo[0];
            } while (c == ' ');
        }
       
        found = tempo.find(',');
        c = tempo[found - 1];
        if (c == ' ') {
            do {
                tempo.erase(found, 1);
                found--;
                c = tempo[found - 1];

            } while (c == ' ');
        }
        copy = tempo.substr(0, found);
        B_PRICE = stod(copy);
        tempo = tempo.substr(found + 1);
        c = tempo[0];
        if (c == ' ') {
            do {
                tempo.erase(std::find(tempo.begin(), tempo.end(), ' '));
                c = tempo[0];
            } while (c == ' ');
        }
        
        found = tempo.find(',');
        copy = tempo.substr(0, found);
        B_YEAR = stoi(copy);
        tempo = tempo.substr(found + 1);
        c = tempo[0];
        if (c == ' ') {
            do {
                tempo.erase(std::find(tempo.begin(), tempo.end(), ' '));
                c = tempo[0];
            } while (c == ' ');
        }
        found = tempo.find('\n');
        copy = tempo.substr(0, found);
        B_DESC = copy;
        tempo = tempo.substr(found + 1);
    }


    std::ostream& operator<< (std::ostream& os, const Book& book) {
        os.width(20);
        os << std::right;
        os << book.B_AUTHOR;
        os << " | ";

        os.width(22);
        os << std::right;
        os << book.B_TITLE;
        os << " | ";

        os.width(5);
        os << std::right;
        os << book.B_COUNTRY;
        os << " | ";

        os.width(4);
        os << std::right;
        os << book.B_YEAR;
        os << " | ";

        os.width(6);
        os << std::fixed;
        os << std::setprecision(2);

        os << std::right;
        os << book.B_PRICE;
        os << " | ";

        os << std::left;
        os << book.B_DESC;
        os << endl;

        return os;
    }


}