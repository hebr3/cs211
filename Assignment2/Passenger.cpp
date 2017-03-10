// Henry Brooks
// CS211

// Implementation file for the Passenger class.
#include "Passenger.h"	// Needed for the Passenger class
#include <string>
#include <iostream>
using namespace std;

// Passenger constructor
Passenger::Passenger(Person person, Preference pref) {
	personInfo = person;
	preferenceInfo = pref;
}

// Accessor functions
Person Passenger::getPersonInfo() const {
	return personInfo;
}
Preference Passenger::getPreferenceInfo() const {
	return preferenceInfo;
}

string Passenger::getID() const {
	return personInfo.getID();
}

bool Passenger::needsAssistance(string criteria) const {
	if (criteria == preferenceInfo.getAssistanceType())
		return true;
	else
		return false;
}

// Mutator functions
void Passenger::setPersonInfo(Person person) {
	personInfo = person;
}
void Passenger::setPreferenceInfo(Preference pref) {
	preferenceInfo = pref;
}

void Passenger::printPassenger() const {
	personInfo.printInfo();
	preferenceInfo.printInfo();
	cout << endl;
}

