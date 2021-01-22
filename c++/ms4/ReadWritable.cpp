#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <iomanip>
#include <sstream>
#include <cstring>
#include"ReadWritable.h"
using namespace std;
namespace sdds {
	bool ReadWritable::isCsv() const {
		return flag;
	}
	void ReadWritable::setCsv(bool value) {
		flag = value;
	}
	std::ostream& operator<<(std::ostream& os, const ReadWritable& bsk) {
		bsk.write(os);
		return os;
	}
	std::istream& operator>>(std::istream& is, ReadWritable& bsk) {
		bsk.read(is);
		return is;
	}
}