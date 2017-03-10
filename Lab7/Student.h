// Henry Brooks
// CS211

// Specification file for the Student class.
#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;
// Student class declaration.

class Student {
	static int totalNumofStudents;
	static long nextStudentID;
	
	friend void setTuition(Student&);
	
	private:
		string name;
		const long studentID;
		string major;
		string classification;
		int units;
		float tuition;
	public:
		Student();								// Default Constructor
		Student(string, string, string, int);
		~Student();								// Default destructor
		
		string getName() const;					// Getters
		long getID() const;
		string getMajor() const;
		string getClassification() const;
		int getUnits() const;
		float getTuition() const;
		int getTotalNumofStudents() const;
		long getNextStudentID() const;
		
		void setName(string);					// Setters
		void setMajor(string);
		void setClassification(string);
		void setUnits(int);
		
		void printStudent() const;
		void setData();
};
#endif
