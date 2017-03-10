// Henry Brooks
// CS211

// Specification file for the Person class.
#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;
// Person class declaration.

class Person {
	private:
		string firstName;
		string lastName;
		char gender;
		long ssn;
	public:
		Person();							// Default constructor
		Person(string, string, char, long);
		
		void setFirstName(string);
		void setLastName(string);
		void setGender(char);
		void setSSN(long);
		
		string getFirstName() const;
		string getLastName()const;
		char getGender() const;
		long getSSN() const;
		
		void printPerson() const;
};
#endif
