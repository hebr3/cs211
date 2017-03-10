// Henry Brooks
// CS211 - Lab7

#include <iostream>
#include <fstream>
#include "Student.h"
using namespace std;

void setTuition(Student &stu) {
	if (stu.classification == "graduate")
		stu.tuition = stu.units * 1000;
	else
		stu.tuition = stu.units * 700;
}

int main () {
	Student student1;
	student1.printStudent();
	
	Student student2 = Student("unknown", "PHYS", "graduate", 0);
	student2.setData(); // "Julia Robertson", "MATH", "undergraduate", 15
	
	setTuition(student2);
	
	student2.printStudent();
	
	return 0;
}
