// Henry Brooks
// CS211

// Implementation file for the Student class.
#include "Student.h"	// Needed for the Student class
#include <string>
#include <iostream>
using namespace std;

int Student::totalNumofStudents = 0;
long Student::nextStudentID = 10000;

// Student constructor
Student::Student() : studentID(nextStudentID) {
	name = "Unknown";
	major = "CS";
	classification = "undergraduate";
	units = 12;
	tuition = 0;
	//	
	totalNumofStudents++;
	nextStudentID++;
}

Student::Student(string theName, string theMajor, string theClassification, int theUnits) : studentID(nextStudentID) {
 	name = theName;
 	major = theMajor;
 	classification = theClassification;
 	units = theUnits;
 	tuition = 0;
 	
 	totalNumofStudents++;
 	nextStudentID++;
}
 
// Student destructor
Student::~Student() {
	totalNumofStudents--;
}

// Student getters
string Student::getName() const {
	return name;
}
long Student::getID() const {
	return studentID;
}
string Student::getMajor() const {
	return major;
}
string Student::getClassification() const {
	return classification;
}
int Student::getUnits() const {
	return units;
}
float Student::getTuition() const {
	return tuition;
}
int Student::getTotalNumofStudents() const {
	return totalNumofStudents;
}
long Student::getNextStudentID() const {
	return nextStudentID;
}
		
void Student::printStudent() const {
	cout << "Student name:   " << name << endl
		 << "Student id:     " << studentID << endl
		 << "Student major:  " << major << endl
		 << "Student class:  " << classification << endl
		 << "Student units:  " << units << endl
		 << "Tuition:        " << tuition << endl;
}

// Student setters
void Student::setName(string n) {
	name = n;
}
void Student::setMajor(string m) {
	major = m;
}
void Student::setClassification(string c) {
	classification = c;
}
void Student::setUnits(int u) {
	units = u;
}

void Student::setData() {
	string n, m, c; 		// Name, Major, and Classification
	int u;					// Units
	cout << "Please enter the students name: ";
	getline(cin, n);
	name = n;
	cout << "Please enter the students major: ";
	cin >> m;
	major = m;
	cout << "Please enter the students classification: ";
	cin >> c;
	classification = c;
	cout << "Please enter the students units: ";
	cin >> u;
	units = u;	
}