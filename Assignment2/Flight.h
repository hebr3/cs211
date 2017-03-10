// Henry Brooks
// CS211

// Specification file for the Flight class.
#ifndef FLIGHT_H
#define FLIGHT_H
#include <string>
#include <vector>
using namespace std;
// Flight class declaration.

class Flight {
	friend ostream& operator << (ostream& os, const Flight& f);

	static long nextFlightNum;
	//friend void FlightReservation::addPassenger(string);
	
	private:
		const long flightNum;
		string departureAirport;
		string arrivalAirport;
		string flightDate;
		string flightTime;
		float flightDuration;
		const int flightCapacity;
		vector<string> passengersID;
	public:
		// Constructors
		Flight(string, string, string, string, float, int);
		
		// Accessors
		long getFlightNum() const;
		string getDepartureAirport() const;
		string getArrivalAirport() const;
		string getFlightDate() const;
		string getFlightTime() const;
		float getFlightDuration() const;
		int getFlightCapacity() const;
		vector<string> getPassengersID() const;
		bool onFlight(string, long) const;
		
		// Mutators
		void setDepartureAirport(string);
		void setArrivalAirport(string);
		void setFlightDate(string);
		void setFlightTime(string);
		void setFlightDuration(float);
		void setPassengersID(vector<string>);
		
		void addPassenger(string);
		void removePassenger(int);
		
		void printPassengersID() const;
		void printFlightInfo() const;
};
#endif