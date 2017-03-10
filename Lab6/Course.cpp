// Henry Brooks
// CS211

// Implementation file for the Course class.
#include "Course.h"	// Needed for the Course class
#include <string>
#include <iostream>
using namespace std;

// Course constructor
Course::Course() {
	long courseNumber = 0;
	string courseName = "CS";
	int numberOfCredits = 0;
}

Course::Course(long num, string name, int cred) {
	courseNumber = num;
	courseName = name;
	numberOfCredits = cred;
}

void Course::setCourseNumber(long num) {
	courseNumber = num;
}

void Course::setCourseName(string name) {
	courseName = name;
}

void Course::setNumberOfCredits(int num) {
	numberOfCredits = num;
}

long Course::getCourseNumber() const {
	return courseNumber;
}

string Course::getCourseName() const {
	return courseName;
}

int Course::getNumberOfCredits() const {
	return numberOfCredits;
}