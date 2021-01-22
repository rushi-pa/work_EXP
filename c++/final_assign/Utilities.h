// Name: Rushi
// Seneca Student ID: 108189192
// Seneca email: rdpatel30@myseneca.ca
// Date of completion: 7/10/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.#include <iostream>
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <iostream>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
class Utilities {
    size_t size_u = 1;
    static char fixed_del;
public:
    void setFieldWidth(size_t total_w);
    size_t getFieldWidth() const;
    std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
    static void setDelimiter(char newDelimiter);
    static char getDelimiter();
    std::string extractTok(const std::string& str) {
        string re = str.substr(0, str.find(fixed_del));
        if (size_u < re.length()) {
            size_u = re.length();
        }
        if (getFieldWidth() < re.length()) {
            setFieldWidth(re.length());
        }
        return re;
    }
};
#endif