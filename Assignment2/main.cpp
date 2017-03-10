// Henry Brooks
// CS211 - Assignment2

#include <iostream>
#include "FlightReservation.h"
using namespace std;

ostream& operator<< (ostream& os, const Flight& c) {
	os << "Flight " << flightNum 
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

int main() {
	
	FlightReservation flightReservation;
	flightReservation.ProcessTransactionFile("TransactionFile.txt");
		
	return 0;
}