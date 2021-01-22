// Ruhsi Patel
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

namespace sdds {
 class Book {
        string B_AUTHOR;
        double B_PRICE;
        string B_TITLE;
        size_t B_YEAR;
        string B_COUNTRY;
        string B_DESC;
    public:
        Book();
        Book(const string&);
        const string& title() const;
        const string& country() const;
        void setPrice(double);
        double& price();
        const size_t& year() const;
        template<class T>
        void fixSpelling(T spellChecker) {
            spellChecker(B_DESC);
        }
        friend ostream& operator<<(ostream&, const Book&);
    };
};
#endif 