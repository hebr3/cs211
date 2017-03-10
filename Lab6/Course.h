// Henry Brooks
// CS211

// Specification file for the Course class.
#ifndef COURSE_H
#define COURSE_H
#include <string>
using namespace std;
// Course class declaration.

class Course {
	private:
		long courseNumber;
		string courseName;
		int numberOfCredits;
	public:
		Course();						// Default Constructor
		Course(long, string, int);
		void setCourseNumber(long); 	// Setters
		void setCourseName(string);
		void setNumberOfCredits(int);
		
		long getCourseNumber() const;	// Getters
		string getCourseName() const;
		int getNumberOfCredits() const;
};
#endif
