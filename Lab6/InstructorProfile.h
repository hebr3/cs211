// Henry Brooks
// CS211

// Specification file for the InstructorProfile class.
#ifndef INSTRUCTOR_PROFILE_H
#define INSTRUCTOR_PROFILE_H
#include <string>
#include <vector>
#include "Instructor.h"
#include "Person.h"
#include "Course.h"
using namespace std;

// InstructorProfile class declaration.

class InstructorProfile {
	private:
		Person personalInfo;
		Instructor instructorInfo;
	public:
		InstructorProfile();	// Constructor
		InstructorProfile(Person, Instructor); // second constructor
		void setPersonalInfo(Person);
		void setInstructorInfo(Instructor);
		Person getPersonalInfo() const;
		Instructor getInstructorInfo() const;
		
		void printInstructorProfile() const;
};
#endif
