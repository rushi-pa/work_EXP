#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Station.h"
#include "Utilities.h"
#include "LineManager.h"
#include <cstring>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>

void LineManager::displayStations() const
{
	for (std::size_t L = 0; L < AssemblyLine.size(); ++L)
	{

		AssemblyLine[L]->display(std::cout);
	}
}
void LineManager::displayCompletedOrders(std::ostream& os) const
{
	for (std::size_t L = 0; L < Completed.size(); ++L)
	{
		Completed[L].display(os);
	}
}
void LineManager::displayStationsSorted() const {

	int S = 0;   // S == START

	for (std::size_t L = 0; L < AssemblyLine.size(); ++L) {

		S = L;

		for (std::size_t N = 0; N < AssemblyLine.size(); ++N) {

			if (AssemblyLine[N]->getNextStation() != nullptr && AssemblyLine[L]->getItemName().compare(AssemblyLine[N]->getNextStation()->getItemName()) == 0) {

				S = -1;
			}
		}

		if (S != -1)
		{
			break;  // Break
		}
	}
	const Workstation* B = AssemblyLine[S];
	while (B != nullptr)
	{
		B->display(std::cout);
		B = B->getNextStation();
	}
}
bool LineManager::run(std::ostream& os) {
	static size_t COUNT = 1;
	os << "Line Manager Iteration: " << COUNT << std::endl;
	COUNT++;
	if (!ToBeFilled.empty())
	{
		int S = 0;   // S == START
		for (std::size_t L = 0; L < AssemblyLine.size(); ++L) {
			S = L;  // S = L;
			for (std::size_t N = 0; N < AssemblyLine.size(); ++N) {
				if (AssemblyLine[N]->getNextStation() != nullptr && AssemblyLine[L]->getItemName().compare(AssemblyLine[N]->getNextStation()->getItemName()) == 0) {

					S = -1;   // S = -1;
				}
			}
			if (S != -1)
			{
				break;
			}
		}
		*AssemblyLine[S] += std::move(ToBeFilled.front());
		ToBeFilled.pop_front();
	}
	for (std::size_t L = 0; L < AssemblyLine.size(); ++L)
	{
		AssemblyLine[L]->runProcess(os);
	}
	for (std::size_t L = 0; L < AssemblyLine.size(); ++L)
	{
		if (AssemblyLine[L]->getNextStation() == nullptr)
		{
			CustomerOrder T;
			if (AssemblyLine[L]->getIfCompleted(T))
			{
				Completed.push_back(std::move(T));
			}
		}
		else
		{
			AssemblyLine[L]->moveOrder();
		}
	}
	if (Completed.size() == m_cntCustomerOrder)
	{
		return true;  // true
	}
	else
		return false;  // false
}
LineManager::LineManager(const std::string& FILE_NAME, std::vector<Workstation*>& WORKSTATION, std::vector<CustomerOrder>& CUSTOMER_ORDER) {
	std::ifstream file(FILE_NAME);
	if (!file)
		throw std::string("Unable to open [") + FILE_NAME + "] file.";
	std::string R;   // R == RECORD
	std::string SEC = "";   // SEC == SECOND
	Utilities U;
	std::string F = "";   // F == first
	bool MORE = true;
	size_t next_pos = 0;
	Workstation* FIRST;  // Workstation* FIRST;
	Workstation* SECOND;   // Workstation* SECOND;
	while (!file.eof())
	{
		std::getline(file, R);
		F = U.extractToken(R, next_pos, MORE);
		if (MORE)
		{
			SEC = U.extractToken(R, next_pos, MORE);
		}
		else {
			SEC = "";
		}
		FIRST = nullptr;
		SECOND = nullptr;
		for (std::size_t L = 0; L < WORKSTATION.size(); ++L) {

			if (WORKSTATION[L]->getItemName().compare(F) == 0)
			{
				FIRST = WORKSTATION[L];
			}
			if (SEC.compare("") != 0 && WORKSTATION[L]->getItemName().compare(SEC) == 0) {
				SECOND = WORKSTATION[L];
			}
		}
		if (SECOND != nullptr)
		{
			FIRST->setNextStation(*SECOND);
		}
	}
	for (std::size_t L = 0; L < CUSTOMER_ORDER.size(); ++L)
	{
		ToBeFilled.push_back(std::move(CUSTOMER_ORDER[L]));
	}
	for (std::size_t L = 0; L < WORKSTATION.size(); ++L)
	{
		AssemblyLine.push_back(WORKSTATION[L]);
	}
	m_cntCustomerOrder = CUSTOMER_ORDER.size();
}
