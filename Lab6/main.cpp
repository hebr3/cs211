// Henry Brooks
// CS211

/* Lab 6 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include "InstructorProfile.h"	// Needed for InstructorProfile class
using namespace std;

int main() {
	// initialize the directory as an empty vector of InstructorProfile
	// and then add the data into the directory from "data.txt"
	vector<InstructorProfile> instructorDirectory;
	ifstream inputfile;
	inputfile.open("data.txt");
	
	cout << setw(10) << "first"
		 << setw(10) << "last"
		 << setw(5) << "sex"
		 << setw(10) << "social"
		 << setw(10) << "id"
		 << setw(10) << "office"
		 << setw(10) << "cnum1"
		 << setw(10) << "cname1"
		 << setw(7) << "cred1"
		 << setw(10) << "cnum2"
		 << setw(10) << "cname2"
		 << setw(7) << "cred2"
		 << setw(10) << "cnum3"
		 << setw(10) << "cname3"
		 << setw(7) << "cred3" << endl;
	
	while(!inputfile.eof()) {
		string first, last;
		char sex;
		long social, id;
		string office;
		long cnum1, cnum2, cnum3;
		string cname1, cname2, cname3;
		int cred1, cred2, cred3;
		inputfile >> first >> last >> sex >> social
				  >> id >> office
				  >> cnum1 >> cname1 >> cred1
				  >> cnum2 >> cname2 >> cred2
				  >> cnum3 >> cname3 >> cred3;
		
		Person p = Person(first, last, sex, social);
		
		vector<Course> c;
		c.push_back(Course(cnum1, cname1, cred1));
		c.push_back(Course(cnum2, cname2, cred2));
		c.push_back(Course(cnum3, cname3, cred3));
		
		Instructor i = Instructor(id, office, c);
		
		InstructorProfile ip = InstructorProfile(p,i);
		
		instructorDirectory.push_back(ip);
		
	}
	inputfile.close();
	
	// Print InstructorProfile's from instructorDirectory
	for (InstructorProfile n : instructorDirectory) {
		n.printInstructorProfile();
	}
	
	
	return 0;
}