// Henry Brooks
// CS211

// Implementation file for the Person class.
#include "Person.h"	// Needed for the Person class
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

// Person constructor
Person::Person() {
	firstName = "First";
	lastName = "Last";
	gender = 'M';
	ssn = 0;		// 000-00-0000
}

Person::Person(string fst, string lst, char g, long s) {
	firstName = fst;
	lastName = lst;
	gender = g;
	ssn = s;		
}

void Person::setFirstName(string first) {
	firstName = first;
}

void Person::setLastName(string last) {
	lastName = last;
}

void Person::setGender(char sex) {
	gender = sex;
}

void Person::setSSN(long social) {
	ssn = social;
}

string Person::getFirstName() const {
	return firstName;
}

string Person::getLastName()const {
	return lastName;
}

char Person::getGender() const {
	return gender;
}

long Person::getSSN() const {
	return ssn;
}

void Person::printPerson() const {
	cout << setw(10) << firstName
		 << setw(10) << lastName
		 << setw(5) << gender
		 << setw(10) << ssn;
}
