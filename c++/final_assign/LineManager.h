#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H
#include <iostream>
#include "Workstation.h"
#include <vector> 
class LineManager
{
	std::vector<Workstation*> AssemblyLine;  
	std::deque<CustomerOrder> ToBeFilled; 
	std::deque<CustomerOrder> Completed; 
	unsigned int m_cntCustomerOrder;  
public:

	LineManager(const std::string&, std::vector<Workstation*>&, std::vector<CustomerOrder>&);
	void displayStations() const;
	void displayCompletedOrders(std::ostream&) const;
	bool run(std::ostream&);
	void displayStationsSorted() const;
};
#endif
