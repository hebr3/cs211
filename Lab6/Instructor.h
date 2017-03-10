// Henry Brooks
// CS211

// Specification file for the Instructor class.
#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include <string>
#include <vector>
#include "Course.h"
using namespace std;

// Instructor class declaration.

class Instructor {
	private:
		long employeeID;
		string officeNum;
		vector<Course> courses;
	public:
		Instructor();	// Constructor
		Instructor(long, string, vector<Course>);
	
		void setEmployeeId(long);
		void setOfficeNum(string);
		void setCourses(Course);
		
		long getEmployeeId() const;
		string getOfficeNum() const;
		vector<Course> getCourses() const;
		
		void printInstructor() const;
};
#endif
