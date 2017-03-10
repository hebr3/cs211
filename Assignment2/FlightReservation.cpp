// Henry Brooks
// CS211

// Implementation file for the FlightReservation class.
#include "FlightReservation.h"	// Needed for the FlightReservation class
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

// FlightReservation constructor
FlightReservation::FlightReservation() { }

// Accessor function
vector<Flight> FlightReservation::getFlights() const {
	return flights;
}
vector<Passenger> FlightReservation::getPassengers() const {
	return passengers;
}
// Mutator function
void FlightReservation::setFlights(Flight flight) {
	flights.push_back(flight);
}
void FlightReservation::setPassengers(Passenger passenger) {
	passengers.push_back(passenger);
}

// Required accessor member functions
void FlightReservation::PrintAllPassengers() const {
	cout << "Printing the current list of passengers" << endl << endl;
	if (passengers.size() == 0) {
		cout << "There are currently no passengers in the flight reservation list" << endl;
		return;
	}
	
	cout << "There are currently " << passengers.size() << " passengers in the list\n\n";
	
	for (Passenger p : passengers) {
		p.printPassenger();			 
	}
}

void FlightReservation::PrintAllFlights() const {
	cout << "Printing the current list of flights" << endl << endl;
	if (flights.size() == 0) {
		cout << "There are currently no flights in the flight reservation list" << endl;
		return;
	}
	
	cout << "There are currently " << flights.size() << " flights in the list\n\n";
	
	for (Flight f : flights) {
		f.printFlightInfo();
	}
}

void FlightReservation::PrintSpecificFlights(string source, string destination, string day) const {
	bool flag = true;
	cout << "Searching flight list for flights" << endl 
		 << "Departing " << source << " for " << destination 
		 << " on " << day << endl << endl;
	for (Flight f : flights) {
		if (source == f.getDepartureAirport() && destination == f.getArrivalAirport() && day == f.getFlightDate()) {
			f.printFlightInfo();
			flag = false;
		}
	}
	
	if (flag)
		cout << "No flight matches those criteria" << endl;
}

void FlightReservation::PrintFlightInfo(long flightNum) const {
	cout << "Printing Flight information for Flight Number " << flightNum << endl << endl;
	
	bool flag = true;
	for (Flight f : flights) {
		if (f.getFlightNum() == flightNum) {
			flag = false;
			f.printFlightInfo();
		}
	}
	
	if (flag)
		cout << "No matching flight found for Flight Number " << flightNum << endl;
}

void FlightReservation::PrintFlightPassengers (long flightNum) const {
	cout << "Printing passenger information for Flight " << flightNum << endl;
	
	bool flag1 = true;
	bool flag2 = true;
	for (Flight f : flights) {
		if (f.getFlightNum() == flightNum) {
			flag1 = false;
			for (string p : f.getPassengersID()) {
				flag2 = false;
				cout << p << endl;
			}
			if (flag2)
				cout << "There are no passengers currently on this flight" << endl;
		}
	}
	if (flag1)
		cout << "There are currently no flights with flight number " << flightNum << endl;
}

void FlightReservation::PrintAssistancePassengers (long flightNum, string assistance) const {
	cout << "Checking flight number " << flightNum << " for passengers needing "
		 << endl << assistance << " assistance" << endl << endl;
	bool flag1 = true;
	bool flag2 = true;
	for (Passenger p : passengers) {
		if (p.needsAssistance(assistance))
			for (Flight f : flights)
				if (f.getFlightNum() == flightNum)
					flag2 = false;
				if (f.onFlight(p.getID(), flightNum)) {
					p.printPassenger();
					flag1 = false;
				}
		}
	
	if (flag2) {
		cout << "Flight number " << flightNum << " is not on the flight list" << endl; 
		return;
	}
	if (flag1) {
		cout << "No passengers on Flight number " << flightNum
			 << " require" << endl << assistance << " assistance" << endl;
		return;
	}
}

bool FlightReservation::IsFlightFull(long flightNum) const {
	cout << "IsFlightFull for flight " << flightNum << " returns ";
	for (Flight f : flights) {
		if (f.getFlightNum() == flightNum)
			if (f.getFlightCapacity() == f.getPassengersID().size()) {
				cout << "true" << endl;
				return true;
			} else {
				cout << "false" << endl;
				return false;
			}
	}
	cout << flightNum << " is not a valid flight number" << endl;
}

// Required mutator member functions
bool FlightReservation::CreateNewPassenger(string ID, string fName, string lName, char sex, int age, string assistance, string meal) {
	cout << "Adding " << fName << " " << lName << " to the passenger list." << endl;
	for (Passenger p : passengers) {
		if (p.getPersonInfo().getID() == ID) {
			cout << "Duplicate passenger ID entered for " << fName << " " << lName << endl;
			cout << "This passenger was not added." << endl;
			return false;
		}
	}
	Person person = Person(ID, fName, lName, sex, age);
	Preference pref = Preference(assistance, meal);
	Passenger pass = Passenger(person, pref);
	passengers.push_back(pass);
	cout << "Passenger " << ID << " successfully added." << endl;
	
	return true;
};

bool FlightReservation::CreateNewFlight(string departAirport, string arriveAirport, string fDate, string fTime, float fDuration, int fCapacity) {
	cout << "Adding flight leaving " << departAirport << " on " << fDate << " at " << fTime << endl;
	for (Flight f : flights) {
		if (f.getDepartureAirport() == departAirport && f.getArrivalAirport() == arriveAirport && f.getFlightDate() == fDate && f.getFlightTime() == fTime && f.getFlightDuration() == fDuration && f.getFlightCapacity() == fCapacity) {
			cout << "Duplicate flight found" << endl;
			cout << "This flight was not added." << endl;
			return false;
		}
	}
	Flight flight = Flight(departAirport, arriveAirport, fDate, fTime, fDuration, fCapacity);
	flights.push_back(flight);
	cout << "Flight " << flight.getFlightNum() 
		 << " from " << departAirport 
		 << " to " << arriveAirport 
		 << " was successfully added." << endl;
	return true;
}

bool FlightReservation::AddFlightPassenger(long flightNum, string passengerID) {
	cout << "Adding passenger " << passengerID << " to flight number " << flightNum << endl;
	for (Flight & f : flights) {
		if (f.getFlightNum() == flightNum) {
			if (f.getFlightCapacity() == f.getPassengersID().size()) {
				cout << "Flight " << flightNum << " is already full" << endl
					 << "Please select a different flight from this list" << endl << endl;
				FlightReservation::PrintSpecificFlights(f.getDepartureAirport(), f.getArrivalAirport(), f.getFlightDate());
				return false;
			}
			for (string id : f.getPassengersID()) {
				/////////////////cout << "<-------- ID " << id << endl;
				if (id == passengerID) {
					cout << "Duplicate passenger found on flight " << flightNum << endl;
					cout << "This passenger was not added." << endl;
					return false;
				}
			}
			f.addPassenger(passengerID);
			int flightCount = f.getPassengersID().size();
			cout << "Passenger " << passengerID << " was successfully added to Flight " 
				 << f.getFlightNum() << endl
				 << "There are now " << flightCount 
				 << " passengers on Flight " << f.getFlightNum() << endl;
			return true;
		}
	}
	cout << "Flight number " << flightNum << " was not found" << endl;
	cout << "This passenger was not added." << endl;
	return false;
}

bool FlightReservation::RemoveFlightPassenger(long flightNum, string passengerID) {
	cout << "Removing " << passengerID << " from flight number " << flightNum << endl;
	for (Flight & f : flights) {
		if (f.getFlightNum() == flightNum) {						// Success
			int count = 0;											// initialize count
			
			for (string id : f.getPassengersID()) {
				if (id == passengerID) {							// Successfully found
					f.removePassenger(count);						// remove
					int flightCount = f.getPassengersID().size();	// get new total
					cout << "Passenger " << passengerID 
						 << " was successfully removed from flight "
						 << flightNum << endl
						 << "There are now " << flightCount 
						 << " passengers on Flight " << f.getFlightNum() << endl;
					return true;
				}
				count++;											// Not found so increment
			}
			
			cout << "Passenger " << passengerID << " was not found on flight "
				 << flightNum << endl;
			return false;
		}
	}
	cout << "Flight number " << flightNum << " was not found" << endl;
	cout << "This passenger could not be removed." << endl;
	
	return false;
}

bool FlightReservation::ProcessTransactionFile(string fileName) {
	// Initialize and open inputfile
	ifstream inputFile(fileName);
	
	if(!inputFile.good()) {
		cout << "Could not read " << fileName << endl
			 << "--------------------------------------------------------\n";
		return false;
	}
	
	while (!inputFile.eof()) {
		string tmp;
		inputFile >> tmp;
		
		string fName, lName, ID, assistance, meal, 
			   departAirport, arriveAirport, fDate, fTime,
			   passengerID;
		char sex;
		int age, fCapacity;
		float fDuration;
		long flightNum;
			
		if (tmp == "CreateNewPassenger") {
			inputFile >> fName >> lName >> ID >> sex >> age >> assistance >> meal;
			FlightReservation::CreateNewPassenger(ID, fName, lName, sex, age, assistance, meal);
		} else if (tmp == "CreateNewFlight") {
			inputFile >> departAirport >> arriveAirport >> fDate >> fTime >> fDuration >> fCapacity;
			FlightReservation::CreateNewFlight(departAirport, arriveAirport, fDate, fTime, fDuration, fCapacity);
		} else if (tmp == "AddFlightPassenger") {
			inputFile >> flightNum >> passengerID;
			FlightReservation::AddFlightPassenger(flightNum, passengerID);
		} else if (tmp == "RemoveFlightPassenger") {
			inputFile >> flightNum >> passengerID;
			FlightReservation::RemoveFlightPassenger(flightNum, passengerID);
		} else if (tmp == "PrintAllPassengers") {
			FlightReservation::PrintAllPassengers();
		} else if (tmp == "PrintAllFlights") {
			FlightReservation::PrintAllFlights();
		} else if (tmp == "PrintSpecificFlights") {
			inputFile >> departAirport >> arriveAirport >> fDate;
			FlightReservation::PrintSpecificFlights(departAirport, arriveAirport, fDate);
		} else if (tmp == "PrintFlightInfo") {
			inputFile >> flightNum;
			FlightReservation::PrintFlightInfo(flightNum);
		} else if (tmp == "PrintAssistancePassengers") {
			inputFile >> flightNum >> assistance;
			FlightReservation::PrintAssistancePassengers(flightNum, assistance);
		} else if (tmp == "isFlightFull") {
			inputFile >> flightNum;
			FlightReservation::IsFlightFull(flightNum);
		} else if (tmp == "PrintFlightPassengers") {
			inputFile >> flightNum;
			FlightReservation::PrintFlightPassengers(flightNum);
		} else
			cout << "The following value is not a valid command: " << tmp << endl;
		
		cout << "-----------------------------------------------------------\n";
		//cout << endl << endl;
	}
	
	// Close the inputFile
	inputFile.close();
	
	return true;
}
