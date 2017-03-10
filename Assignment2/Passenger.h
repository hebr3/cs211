// Henry Brooks
// CS211

// Specification file for the Passenger class.
#ifndef Passenger_H
#define Passenger_H
#include "Person.h"
#include "Preference.h"
using namespace std;

// Passenger class declaration.
class Passenger {
	private:
		Person personInfo;
		Preference preferenceInfo;
	public:
		// No default Constructor
		Passenger(Person, Preference);
		
		Person getPersonInfo() const;					// Getters
		Preference getPreferenceInfo() const;
		
		void setPersonInfo(Person);					// Setters
		void setPreferenceInfo(Preference);
		
		void printPassenger() const;
		
		bool needsAssistance(string) const;
		string getID() const;
};
#endif