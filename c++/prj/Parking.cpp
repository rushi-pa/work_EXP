#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <iomanip>
#include <sstream>
#include <cstring>
#include"Parking.h"
#include<fstream>
using namespace std;
namespace sdds {
	Parking::Parking(const char* naame, int spots) :Menu("Parking Menu, select an action:", 0) {
		setEmpty();
		name = nullptr;
		if (naame == nullptr || naame[0] == '\0') {
			bool i = LoadData();
			if (i == true) {
			}
		}
		else {
			if (spots < 10 || spots >MAX_CARS) {
				cout << "Unable to craete the object";
			}
			else {

				bool i = true;
				if (i == true) {
					add("Park Vehicle");
					add("Return Vehicle");
					add("List Parked Vehicles");
					add("Close Parking (End of day)");
					add("Exit Program");
					noOfSpots = spots;
					count = 0;
					//vehicle = new Vehicle[noOfSpots];
					for (int i = 0; i < noOfSpots; i++) {
						//	vehicle[i] = new Vehicle;
						vehicle[i] = nullptr;
						//	vehicle[i]->setEmpty();
					}
					count = 0;
					noOfSpots = spots;
					setTitle(naame);
					bool i = LoadData();
					if (i == true) {
					}
					//count = 0;
				}
				else {
					delete[] name;
				}
			}

		}
	}
	Parking::~Parking() {
		save();
		delete[] name;
		for (int i = 0; i < noOfSpots; i++) {
			delete vehicle[i];
		}
	}
	void Parking::setEmpty() {
		name = nullptr;
		count = 0;
		noOfSpots = 0;
	}
	void Parking::setTitle(const char* naaame) {
		if (name != nullptr)
			delete[] name;
		if (ismpty() == true) {
			name = new char[strlen(naaame) + 1];
			strcpy(name, naaame);
			name[strlen(naaame)] = '\0';
		}

	}

	bool Parking::ismpty() {
		if (name == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}
	void Parking::status() {
		cout << "****** Seneca Valet Parking ******" << endl;
		cout << "*****  Available spots: " << noOfSpots - count; 
		if((noOfSpots - count) >= 10){
			cout<< "   *****" << endl;}else{
			cout<<"    *****"<<endl;}
	}
	void Parking::retuVeh() {
		cout << "Return Vehicle" << endl;
		char  a[10];
		a[0] = '\0';
		int q = 0;
		//cin.ignore(2000, '\n');
		cout << "Enter Licence Plate Number: ";
		do {
			//	a = getStringInRange(cin,1,8,"licence Plate");
			cin.get(a, 9);
			cin.ignore(2000, '\n');

			if (strlen(a) < 1 || strlen(a) > 8) {
				cout << "Invalid Licence Plate, try again: ";
			}
			else {
				q = 1;
			}
		} while (q == 0);
		//cout << a;
		int value = 0;
		int boom = 40;
		for (int i = 0; i <= noOfSpots; i++) {
			if (vehicle[i] == nullptr) {

			}
			else {
				value = vehicle[i]->Vehicle::returnplate(*vehicle[i], a);
				if (value == 1) {
					boom = i;
					i = noOfSpots;
				}
			}
		}
		if (boom == 40) {
			cout << "License plate " << a << " Not found" << endl;
		}
		else {
			cout << endl;
			cout << "Returning: " << endl;;
			vehicle[boom]->write(cout);
			cout << endl;
			delete vehicle[boom];
			vehicle[boom] = nullptr;
			count--;
			cout << endl;
		}
	}
	void Parking::list() {
		cout << "*** List of parked vehicles ***" << endl;
		//vehicle->setCsv(false);
		for (int i = 0; i < noOfSpots; i++) {
			if (vehicle[i] == nullptr) {
				//cout << "ahiya kyak bhul che";
				
			}
			else {
				vehicle[i]->write(cout);
				cout << endl;
				cout << "-------------------------------" << endl;
			}
		}
	}
	bool Parking::close() {

		int temp = 0;
		bool rtemp;
		char value[10];
		cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";
		do {

			cin >> value;
			while (getchar() != '\n');
			if (value[1] == '\0' && (value[0] == 'y' || value[0] == 'Y'))
			{
				rtemp = true;
				temp = 1;
			}
			else {
				if (value[1] == '\0' && (value[0] == 'n' || value[0] == 'N')) {
					temp = 1;
					rtemp = false;
					cout << "Aborted!" << endl;
				}
				else {
					cout << "Invalid response, only(Y)es or (N)o are acceptable, retry: ";
					temp = 0;
					rtemp = false;
					value[0] = '\0';
				}
			}
		} while (temp == 0);
		if (rtemp == true) {
			cout << "Closing Parking";
			for (int i = 0; i < noOfSpots; i++) {

				if (vehicle[i] != nullptr) {
					cout<<endl;
					cout << endl;
					cout << "Towing request" << endl;
					cout << "*********************" << endl;
					vehicle[i]->write(cout);
					delete vehicle[i];
					vehicle[i] = nullptr;
				}
			}
		}
		return rtemp;
	}
	void Parking::Park(int i) {
		if (i == 1) {
			cout << "Parking Car" << endl;
		}
		else {
			if (i == 2) {
				cout << "Parking Motorcycle" << endl;
			}
			else {
				if (i == 3) {
					cout << "Cancelled parking" << endl;
				}
			}
		}
	}
	bool Parking::Exit() {
		cout << "This will terminate the program!" << endl;
		int temp = 0;
		bool rtemp;
		char value[10];
		cout << "Are you sure? (Y)es/(N)o: ";
		do {

			cin >> value;
			while (getchar() != '\n');
			if (value[1] == '\0' && (value[0] == 'y' || value[0] == 'Y'))
			{
				rtemp = true;
				temp = 1;
			}
			else {
				if (value[1] == '\0' && (value[0] == 'n' || value[0] == 'N')) {
					temp = 1;
					rtemp = false;
				}
				else {
					cout << "Invalid response, only(Y)es or (N)o are acceptable, retry: ";
					temp = 0;
					rtemp = false;
					value[0] = '\0';
				}
			}
		} while (temp == 0);
		if (rtemp == true) {
			cout << "Exiting program!";
		}
		return rtemp;
	}

	bool Parking::LoadData() {
		if (ismpty() == true) {
			cout << "Error in data file" << endl;
			return false;
		}
		else {
			char type;
			int no = 0;
			std::ifstream f(name);
			if ((f.peek() == std::ifstream::traits_type::eof()) != true) {
				if (f.is_open()) {
					//while (f) {
					for (int i = 0; i <= noOfSpots; i++) {
						f.get(type);
						f.ignore(500, ',');
						no++;
						if (no == 1 && type != 'M' && type != 'm' && type != 'c' && type != 'C') {
							for (int i = 0; i < noOfSpots; i++) {
								vehicle[i] = nullptr;
							}
							break;
						}
						//cout << no;
						//no++;
						//cout << type[0];
						if (type == 'M' || type == 'm') {
							vehicle[count] = new Motorcycle;
							vehicle[count]->Vehicle::setCsv(true);
							vehicle[count]->read(f);
							vehicle[count]->setParkingSpot(count + 1);
							//no++;

							//f.ignore(2000, '\n');
							vehicle[count]->Vehicle::setCsv(false);
							count++;
							type = '\0';
							/*if (vehicle[no]->isty() == true) {
								delete[] vehicle[no];
								no--;
							}*/
						}
						else {
							if (type == 'C' || type == 'c') {
								vehicle[count] = new Car;
								vehicle[count]->Vehicle::setCsv(true);
								vehicle[count]->read(f);
								vehicle[count]->setParkingSpot(count + 1);
								//no++;

								//f.ignore(2000, '\n');
								vehicle[count]->Vehicle::setCsv(false);
								count++;
								type = '\0';
								/*if (vehicle[no]->isty() == true) {
									delete[] vehicle[no];
									no--;
								}
								//}*/
							}
							else {
								if (type == '\0') {
									vehicle[count] = nullptr;
								}
							}
						}
					}
					//		count--;
							//	cout << "loading data from ";
							//	for (size_t i = 0; i < strlen(name); i++) {

							//		cout << name[i];

							//	}
							//	cout << endl;
				}
			}
			f.close();


			return true;
		}
	}
	/*bool Parking::LoadData()
	{
		bool state = true;
		if (!ismpty())
		{
			ifstream f(name);
			if (f.is_open())
			{

				while (state && f && !(f >> std::ws).eof())
				{

					char temp;
					f.get(temp);
					f.ignore();
					if (temp == 'M' || temp == 'C')
					{
						Vehicle* tempVehicle;
						if (temp == 'M')
						{
							tempVehicle = new Motorcycle();
						}
						else
						{
							tempVehicle = new Car();
						}
						tempVehicle->setCsv(true);
						tempVehicle->read(f);
						if (!f.fail()) // check to see if read was successful
						{
							state = true;

							for (int i = 0; i < noOfSpots; i++) //looping through parkingSpots to find the first empty member
							{
								if (vehicle[i] == nullptr) {
									vehicle[i] = tempVehicle;
									vehicle[i]->setParkingSpot(i + 1);
									delete tempVehicle;
									count++;
									break;
								}
							}
						}
						else
						{
							state = false;
							delete tempVehicle;
						}
					}
					else
					{
						state = false;
					}

				}

			}
			else
			{
				state = false;
			}

		}
		else
		{
			state = false;
		}

		return state;
	}*/
	void Parking::save() {
		std::ofstream f(name);
		if (f.is_open()) {
			for (int i = 0; i < noOfSpots; i++) {
				if (vehicle[i] != nullptr) {
					vehicle[i]->setCsv(true);
					vehicle[i]->write(f);
					//f << *vehicle[i];
					//f << endl;
				}
			}
			cin.ignore(1000, '\n');
			f.close();
		}
	}
	int Parking::run() {
		if (ismpty() == true) {
			return 1;
		}
		else {
			int k = 0;
			do {
				status();
				//display();
				int temp = 0;
				//P1.setT("Select Type of Vehicle");
				temp = Menu::run();

				if (temp == 1) {
					if ((noOfSpots - count) == 0) {
						cout << "Parking is full" << endl;
					}
					else {
						k = 0;
						int j = 0;
						cout << "    Select type of the vehicle:" << endl;
						cout << "    1- Car" << endl;
						cout << "    2- Motorcycle" << endl;
						cout << "    3- Cancel" << endl;
						cout << "    > ";
						char a[2] = { '\0','\0' };
						int i = 0;
						do {

							cin >> a;
							if (a[0] == '1' || a[0] == '2' || a[0] == '3') {
								if (a[0] == '1') {
									i = 1;
								}
								else {
									if (a[0] == '2') {
										i = 2;
									}
									else {
										i = 3;
									}
								}
								j = 1;
							}
							else {
								if (a[0] == 'n' || a[0] == 'y') {
									cout << "Invalid Integer, try again: ";
									//clear();
								}
								else {
									cout << "Invalid selection, try again: ";
									//clear();
								}

							}
						} while (j == 0);
						if ((noOfSpots - count) == 0) {
							cout << "Parking is full" << endl;
							//k = 1;
						}
						else {
							//Park(i);
							if (i == 3) {
								cout << "Parking cancelled" << endl;
							}
							if (i == 2) {
								int t = 0;
								int loop = 0;
								int emp = 0;
								int check = 0;
								do {
									if (vehicle[loop] == nullptr) {
										emp = loop;
										t = 1;
										//		if (vehicle[loop + 1] != nullptr) {
										//			check = 1;
										//		}
									}
									else {
										loop++;
									}
								} while (t == 0);
								if (emp > noOfSpots) {
									cout << "full;";
								}
								else {
									if (check == 1) {
										vehicle[emp] = new Motorcycle;

										//vehicle[count] = nullptr;
										//Car* temp;
										//temp = new Car;
										int btw = 0;
										vehicle[emp]->Vehicle::setCsv(false);
										cout << endl;
										vehicle[emp]->read(cin);
										//vehicle[emp] = temp;
										for (int i = 0; i < count; i++) {
											if (*vehicle[i] == *vehicle[count]) {
												delete vehicle[emp];
												vehicle[emp] = nullptr;
												//count--;
												k = 1;

											}
											else {
												if (btw == 0) {
													cout << endl;
													cout << "Parking Ticket" << endl;
													vehicle[emp]->setParkingSpot(emp);
													//vehicle[emp]->write(cout);
													cout << endl;
													btw = 1;
												}
											}
										}
										//delete temp;
										//count++;
									}
									else {
										vehicle[emp] = new Motorcycle;
										//vehicle[count] = nullptr;
										//Car* temp;
										//temp = new Car;
										vehicle[emp]->Vehicle::setCsv(false);
										int btw = 0;
										cout << endl;
										vehicle[emp]->read(cin);
										//vehicle[emp] = temp;
										count++;
										for (int i = 0; i < count; i++) {
											if (*vehicle[i] == *vehicle[emp]) {
												if (emp != i) {
													delete vehicle[emp];
													vehicle[emp] = nullptr;
													count--;
													//k = 1;
													cout << endl;
													cout << "Can not park; license plate already in the system!" << endl;

													cout << "Parking Ticket" << endl;
													vehicle[i]->setParkingSpot(i + 1);
													vehicle[i]->write(cout);
													cout << endl;
													btw = 1;
													cout << endl;
												}
												else {
													if (btw == 0) {
														cout << endl;
														cout << "Parking Ticket" << endl;
														vehicle[i]->setParkingSpot(i + 1);
														vehicle[i]->write(cout);
														cout << endl;
														btw = 1;
														cout << endl;
													}
												}
											}
										}
										{
											if (btw == 0) {
												cout << endl;
												cout << "Parking Ticket" << endl;
												vehicle[emp]->setParkingSpot(emp + 1);
												vehicle[emp]->write(cout);
												cout << endl;
												btw = 1;
												cout << endl;
											}
										}

										//delete temp;
										//count++;
									}
								}
							}
							if (i == 1) {
								int t = 0;
								int loop = 0;
								int emp = 0;
								int check = 0;
								do {
									if (vehicle[loop] == nullptr) {
										emp = loop;
										t = 1;
										if (vehicle[loop + 1] != nullptr) {
											check = 1;
										}
									}
									else {
										loop++;
									}
								} while (t == 0);
								if (emp > noOfSpots) {
									cout << "full;";
								}
								else {
									if (check == 1) {
										vehicle[emp] = nullptr;
										//	vehicle[emp]->setEmpty();
										vehicle[emp] = new Car;

										//vehicle[count] = nullptr;
										//Car* temp;
										//temp = new Car;
										vehicle[emp]->Vehicle::setCsv(false);
										//int btw = 0;
										cout << endl;
										vehicle[emp]->read(cin);
										//vehicle[emp] = temp;
									count++;
										cout << endl;
										cout << "Parking Ticket" << endl;
										vehicle[emp]->setParkingSpot(emp + 1);
										vehicle[emp]->write(cout);
										cout << endl;
										//btw = 1;
										cout << endl;
										//delete temp;
										//count++;
									}
									else {
										vehicle[emp] = nullptr;
										//	vehicle[emp]->setEmpty();
										vehicle[emp] = new Car;

										//vehicle[count] = nullptr;
										//Car* temp;
										//temp = new Car;
										vehicle[emp]->Vehicle::setCsv(false);
										int btw = 0;
										cout << endl;
										vehicle[emp]->read(cin);
										//vehicle[emp] = temp;
										count++;
										for (int i = 0; i < count; i++) {
											if (*vehicle[i] == *vehicle[emp]) {
												if (emp != i) {
													delete vehicle[emp];
													vehicle[emp] = nullptr;
													count--;
													//k = 1;
													cout << endl;
													cout << "Can not park; license plate already in the system!" << endl;

													cout << "Parking Ticket" << endl;
													vehicle[i]->setParkingSpot(i + 1);
													vehicle[i]->write(cout);
													cout << endl;
													btw = 1;
													cout << endl;
												}
												else {
													if (btw == 0) {
														cout << endl;
														cout << "Parking Ticket" << endl;
														vehicle[i]->setParkingSpot(i + 1);
														vehicle[i]->write(cout); 
														cout << endl;
														btw = 1;
														cout << endl;
													}
												}
											}
											else {
												if (btw == 0) {
													cout << endl;
													cout << "Parking Ticket" << endl;
													vehicle[emp]->setParkingSpot(emp + 1);
													vehicle[emp]->write(cout);
													cout << endl;
													btw = 1;
													cout << endl;
												}
											}
										}
										//delete temp;
										//count++;
									}
								}
							}
						}

					}
				}
				else {
					if (temp == 2) {
						retuVeh();
					}
					if (temp == 3) {
						list();
					}
					if (temp == 4) {
						bool i = close();
						if (i == true) {
							k = 1;
						}
						else {
							k = 0;
						}
					}
					if (temp == 5) {
						bool i = Exit();
						if (i == true) {
							k = 1;
						}
						else {
							k = 0;
						}
					}
				}
			} while (k == 0);
			return 0;
		}
	}
}
