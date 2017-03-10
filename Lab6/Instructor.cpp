// Henry Brooks
// CS211

// Implementation file for the Instructor class.
#include "Instructor.h"	// Needed for the Instructor class
#include <string>		// Needed for strings
#include <iostream>		// Needed for cout
#include <vector>		// Needed for vector of courses
#include <iomanip>
#include <iostream>
using namespace std;

// Instructor constructor
Instructor::Instructor() {
	employeeID = 0;
	officeNum = "0";
	vector<Course> courses(3);
}

Instructor::Instructor(long id, string office, vector<Course> c) {
	employeeID = id;
	officeNum = office;
	courses = c;
}

void Instructor::setEmployeeId(long ID) {
	employeeID = ID;
};

void Instructor::setOfficeNum(string num) {
	officeNum = num;
} 

void Instructor::setCourses(Course c) {
	courses.push_back(c);
}

long Instructor::getEmployeeId() const {
	return employeeID;
}

string Instructor::getOfficeNum() const {
	return officeNum;
}

vector<Course> Instructor::getCourses() const {
	return courses;
}

void Instructor::printInstructor() const {
	cout << setw(10) << employeeID
		 << setw(10) << officeNum;
	for (Course cl : courses) { 
		cout << setw(10) << cl.getCourseNumber()
			 << setw(10) <<cl.getCourseName()
			 << setw(7) <<cl.getNumberOfCredits();
	}
	cout << endl;
}