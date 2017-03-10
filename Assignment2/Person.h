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
		string ID;
		string firstName;
		string lastName;
		char gender;
		int age;
	public:
		// Constructors
		Person();
		Person(string, string, string, char, int);
		
		// Accessors
		string getID() const;
		string getFirstName() const;
		string getLastName() const;
		char getGender() const;
		int getAge() const;
		
		// Mutators
		void setID(string);
		void setFirstName(string);
		void setLastName(string);
		void setGender(char);
		void setAge(int);
		
		void printInfo() const;
};
#endif