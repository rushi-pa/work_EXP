#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
#include <iostream>
#include "Station.h"
#include "CustomerOrder.h"
#include <string>
#include <deque>
class Workstation : public Station
{
	std::deque<CustomerOrder> orders;
	Workstation* ChangeStation;
public:
	void setNextStation(Workstation&);
	void display(std::ostream&)const;
	Workstation& operator+=(CustomerOrder&&);
	bool moveOrder();
	const Workstation* getNextStation() const;
	bool getIfCompleted(CustomerOrder&);
	Workstation& operator=(const Workstation& other) = delete;
	Workstation(const Workstation& p2) = delete;
	Workstation(Workstation&& a) noexcept = delete;
	Workstation(const std::string&);
	Workstation& operator=(Workstation&& a) noexcept = delete;
	void runProcess(std::ostream&);
};
#endif
