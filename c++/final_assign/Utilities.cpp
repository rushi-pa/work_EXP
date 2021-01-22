//*Name: Rushi
// Seneca Student ID: 108189192
// Seneca email: rdpatel30@myseneca.ca
// Date of completion: 7/10/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.*/
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include "Utilities.h"
using namespace std;
char Utilities::fixed_del = ' ';
char Utilities::getDelimiter()
{
	return fixed_del;
}
void Utilities::setDelimiter(char newDelimiter)
{
	fixed_del = newDelimiter;
}

void Utilities::setFieldWidth(size_t newWidth)
{
	size_u = newWidth;
}
size_t Utilities::getFieldWidth() const
{
	return size_u;
}
std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {

	string T = "";
	size_t P_POS = next_pos;

	next_pos = str.find(fixed_del, P_POS);

	if (next_pos == string::npos)
	{
		T = str.substr(P_POS);

		size_u = max(T.length(), size_u);

		more = false;
	}
	else if (P_POS == next_pos)
	{
		more = false;
		throw "No token between delimiters!";
	}
	else {
		T = str.substr(P_POS, next_pos - P_POS);
		size_u = max(T.length(), size_u);
		more = true;   // more = true;
	}
	next_pos++;  // next_pos++;
	return T;   // return T;
}
