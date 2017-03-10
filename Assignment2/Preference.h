// Henry Brooks
// CS211

// Specification file for the Preference class.
#ifndef PREFERENCE_H
#define PREFERENCE_H
#include <string>
using namespace std;
// Preference class declaration.

class Preference {
	private:
		string assistanceType,	// wheelchair, bassinet, child, none
			   mealType;		// vegetarian, chicken, fish
	public:
		// Constructors
		Preference();
		Preference(string, string);
		
		string getAssistanceType() const;					// Getters
		string getMealType() const;
		
		void setAssistanceType(string);					// Setters
		void setMealType(string);
	
		void printInfo() const;
};
#endif