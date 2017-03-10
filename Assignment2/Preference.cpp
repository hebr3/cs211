// Henry Brooks
// CS211

// Implementation file for the Preference class.
#include "Preference.h"	// Needed for the Preference class
#include <string>
#include <iostream>
using namespace std;

// Preference constructor
Preference::Preference() {
	assistanceType = "none";
	mealType = "vegetarian";
}
Preference::Preference(string at, string mt) {
	assistanceType = at;
	mealType = mt;
}

// Getter functions
string Preference::getAssistanceType() const {
	return assistanceType;
}
string Preference::getMealType() const {
	return mealType;
}


// Setter functions
void Preference::setAssistanceType(string at) {
	assistanceType = at;
}
void Preference::setMealType(string mt) {
	mealType = mt;
}

void Preference::printInfo() const {
	cout << "Assistance: " << assistanceType << endl
		 << "Meal type:  " << mealType << endl;
}