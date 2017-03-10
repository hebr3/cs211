// Henry Brooks
// CS211

// Specification file for the FlightReservation class.
#ifndef FLIGHTRESERVATION_H
#define FLIGHTRESERVATION_H
#include <string>
#include <vector>
#include "Flight.h"
#include "Passenger.h"
using namespace std;
// FlightReservation class declaration.

class FlightReservation {
	static bool failure;
	static bool success;
	
	private:
		vector<Flight> flights;
		vector<Passenger> passengers;
	public:
		// Constructors
		FlightReservation();
		
		// Accessors
		vector<Flight> getFlights() const;
		vector<Passenger> getPassengers() const;
		// Mutators
		void setFlights(Flight);
		void setPassengers(Passenger);

		// Required accessor member functions
		void PrintAllPassengers() const;
		void PrintAllFlights() const;
		void PrintSpecificFlights(string, string, string) const;
		void PrintFlightInfo (long) const;
		void PrintFlightPassengers (long) const;
		void PrintAssistancePassengers (long flightNum, string assistance) const;		
		bool IsFlightFull(long flightNum) const;
		
		// Required mutator member functions
		bool CreateNewPassenger(string, string, string, char, int, string, string);
		bool CreateNewFlight (string, string, string, string, float, int);
		bool AddFlightPassenger(long, string);
		bool RemoveFlightPassenger(long, string);
		bool ProcessTransactionFile(string);
		vector<string> ProcessTransactionFileHelper(string);

		
};
#endif
