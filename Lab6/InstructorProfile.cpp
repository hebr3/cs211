// Henry Brooks
// CS211

// Implementation file for the InstructorProfile class.
#include "InstructorProfile.h"	// Needed for the Instructor class
#include <string>		// Needed for strings
#include <vector>		// Needed for vector of courses
#include "Person.h"
#include "Instructor.h"
#include <iomanip>
#include <iostream>
using namespace std;

// Instructor constructor
InstructorProfile::InstructorProfile() {
	Person personalInfo = Person();
	Instructor instructorInfo = Instructor();
}

InstructorProfile::InstructorProfile(Person perInfo, Instructor instInfo) {
	personalInfo = perInfo;
	instructorInfo = instInfo;
}

void InstructorProfile::setPersonalInfo(Person perInfo) {
	personalInfo = perInfo;
}

void InstructorProfile::setInstructorInfo(Instructor instInfo) {
	instructorInfo = instInfo;
} 

Person InstructorProfile::getPersonalInfo() const {
	return personalInfo;
}

Instructor InstructorProfile::getInstructorInfo() const {
	return instructorInfo;
}

void InstructorProfile::printInstructorProfile() const {
	personalInfo.printPerson();
	instructorInfo.printInstructor();
}