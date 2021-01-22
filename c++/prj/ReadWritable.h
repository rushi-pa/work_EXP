#pragma once
#pragma once
#ifndef SDDS_READWRITABLE_H
#define SDDS_READWRITABLE_H
#include<iostream>
#include<ostream>
using namespace std;
namespace sdds
{
	class ReadWritable {
		bool flag = false;
	public:
		ReadWritable() {
			flag = false;
		};
		virtual ~ReadWritable() {};
		bool isCsv() const;
		void setCsv(bool value);
		virtual std::istream& read(std::istream& istr = std::cin) = 0;
		virtual std::ostream& write(std::ostream& ostr = std::cout)const = 0;
		friend std::ostream& operator<<(std::ostream& os, const ReadWritable& bsk);
		friend std::istream& operator>>(std::istream& is, ReadWritable& bsk);
	};
	std::ostream& operator<<(std::ostream& os, const ReadWritable& bsk);
	std::istream& operator>>(std::istream& is, ReadWritable& bsk);
};

#endif