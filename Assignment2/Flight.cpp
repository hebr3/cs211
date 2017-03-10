// Henry Brooks
// CS211

// Implementation file for the Flight class.
#include "Flight.h"	// Needed for the Flight class
#include <string>
#include <iostream>
#include <vector>
using namespace std;

// Static value
long Flight::nextFlightNum = 100;

// Flight constructor
Flight::Flight(string da, string aa, string fd, string ft, float t, int c) : flightNum(nextFlightNum), flightCapacity(c) {
	departureAirport = da;
	arrivalAirport = aa;
	flightDate = fd;
	flightTime = ft;
	flightDuration = t;
	nextFlightNum += 10;
}

// Getter functions
long Flight::getFlightNum() const {
	return flightNum;
}
string Flight::getDepartureAirport() const {
	return departureAirport;
}
string Flight::getArrivalAirport() const {
	return arrivalAirport;
}
string Flight::getFlightDate() const {
	return flightDate;
}
string Flight::getFlightTime() const {
	return flightTime;
}
float Flight::getFlightDuration() const {
	return flightDuration;
}
int Flight::getFlightCapacity() const {
	return flightCapacity;
}
vector<string> Flight::getPassengersID() const {
	return passengersID;
}
bool Flight::onFlight(string criteria, long fNum) const {
	for (string p : passengersID)
		if (p == criteria && flightNum == fNum)
			return true;
	return false;
}

// Setter functions
void Flight::setDepartureAirport(string da) {
	departureAirport = da;
}
void Flight::setArrivalAirport(string aa) {
	arrivalAirport = aa;
}
void Flight::setFlightDate(string fd) {
	flightDate = fd;
}
void Flight::setFlightTime(string ft) {
	flightTime = ft;
}
void Flight::setFlightDuration(float t) {
	flightDuration = t;
}
void Flight::setPassengersID(vector<string> vectorOfPassengers) {
	passengersID = vectorOfPassengers;
}

void Flight::addPassenger(string id) {
	passengersID.push_back(id);
}

void Flight::removePassenger(int i) {
	passengersID.erase(passengersID.begin()+i);
}

void Flight::printPassengersID() const {
	for (string p : passengersID) {
		cout << p << " is a passenger on flight " << flightNum << endl;
	}
}

void Flight::printFlightInfo() const {
	cout << "Flight " << flightNum 
		 << " departs " << departureAirport 
		 << " at " << flightTime
		 << " on " << flightDate 
		 << endl
		 << "Flight arrives at " << arrivalAirport 
		 << " after " << flightDuration
		 << " hours" << endl 
		 << "Currently " << passengersID.size() << " of " 
		 << flightCapacity << " seats are taken" << endl << endl;
}