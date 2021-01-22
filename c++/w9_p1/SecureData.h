/**********************************************************
 * Name: Parsa Parichehreh
 * Student ID: 156794182
 * Seneca email: pparichehreh1@myseneca.ca
 * Course: OOP345
 * Section: NCC
 * Date: July 29, 2020 
 * Workshop 9 Part 1
 **********************************************************/

 /**********************************************************
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments.

  **********************************************************/


// Workshop 9 - Multi-Threading
// SecureData.h
#ifndef W9_SECUREDATA_H
#define W9_SECUREDATA_H

#include <iostream>

namespace w9 {
    class Cryptor {
    public:
        char operator()(char in, char key) const { return in ^ key; }
    };

    void converter(char*, char, int, const Cryptor&);

    class SecureData {
        char* text;
        std::ostream* ofs;
        int nbytes;
        bool encoded;

        void code(char);

    public:
        SecureData(const char*, char, std::ostream*);

        SecureData(const SecureData&) = delete;

        SecureData& operator=(const SecureData&) = delete;

        ~SecureData();

        void display(std::ostream&) const;

        void backup(const char*);

        void restore(const char*, char);
    };

    std::ostream& operator<<(std::ostream&, const SecureData&);
}
#endif