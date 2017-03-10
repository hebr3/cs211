// Henry Brooks
// CS211

// Implementation file for the Person class.
#include "Person.h"	// Needed for the Person class
#include <string>
#include <iostream>
using namespace std;

// Person constructor
Person::Person() {
	ID = "NoID";
	firstName = "John";
	lastName = "Doe";
	gender = 'M';
	age = 0;
}
Person::Person(string id, string fst, string lst, char s, int a)  {
	ID = id;
	firstName = fst;
	lastName = lst;
	gender = s;
	age = a;
}

// Accessors functions
string Person::getID() const {
	return ID;
}
string Person::getFirstName() const {
	return firstName;
}
string Person::getLastName() const {
	return lastName;
}
char Person::getGender() const {
	return gender;
}
int Person::getAge() const {
	return age;
}

// Mutators functions
void Person::setID(string id) {
	ID = id;
}
void Person::setFirstName(string fst) {
	firstName = fst;
}
void Person::setLastName(string lst) {
	lastName = lst;
}
void Person::setGender(char s) {
	gender = s;
}
void Person::setAge(int a) {
	age = a;
}

void Person::printInfo() const {
	cout << "First name: " << firstName << endl
		 << "Last name:  " << lastName << endl
		 << "Age:        " << age << endl
		 << "Gender:     " << gender << endl
		 << "ID:         " << ID << endl;
}