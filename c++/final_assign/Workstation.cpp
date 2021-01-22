#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "Utilities.h"
#include "Workstation.h"
#include "Station.h"
#include <string>
#include <cstring>
using namespace std;

bool Workstation::getIfCompleted(CustomerOrder& order) 
{
	if (orders.empty()) 
	{
		return false;
	}
	if (orders.front().isOrderFilled()) 
	{
		order = move(orders.front());
		orders.pop_front();
		return true;
	}
	else 
	{
		return false;
	}
}
Workstation::Workstation(const std::string& S) :Station(S) 
{
	ChangeStation = nullptr;
}
void Workstation::display(std::ostream& OS) const {

	if (ChangeStation == nullptr)
		OS << getItemName() << " --> END OF LINE" << endl;
	else
		OS << getItemName() << " --> " << ChangeStation->getItemName() << endl;
}
void Workstation::runProcess(std::ostream& OS) 
{
	if (orders.empty()) 
	{
		return;
	}
	orders.front().fillItem(*this, OS);
}

const Workstation* Workstation::getNextStation() const
{
	return ChangeStation;
}
void Workstation::setNextStation(Workstation& station)
{
	ChangeStation = &station;
}
Workstation& Workstation::operator+=(CustomerOrder&& Assembly_l)
{
	orders.push_back(std::move(Assembly_l));
	return *this;
}
bool Workstation::moveOrder() {
	if (orders.empty())
	{
		return false;
	}
	if (orders.front().isItemFilled(getItemName()) == true)
	{
		*ChangeStation += std::move(orders.front());
		orders.pop_front();
		return true;  // return true;
	}
	else
	{
		return false;  // return false;
	}
}