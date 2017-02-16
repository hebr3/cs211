// Henry Brooks
// CS211 
// brook057@cougars.csusm.edu
// 02/10/2017

/*
Program 2:
Write a program that reads a string from the user containing a date in the form mm/dd/yyyy and saves it in another string in the form month day, year and then prints it.
For example,
if the user enters 12/18/2017, the output should be December 18, 2017. 
if the user enters 01/08/2017, the output should be January 8, 2017.
Note: you may use the c_str() member function which converts the contents of a string object to a C-string and the atoi function which accepts a C-string and converts it to an integer and returns that integer value. 
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {
	cout << "Please enter a date: ";
	
	vector<string> months;
	months = {"January",
			  "February",
			  "March",
			  "April",
			  "May",
			  "June",
			  "July",
			  "August",
			  "September",
			  "October",
			  "November",
			  "December"};
	
	string input;
	
	cin >> input;
	
	string month = input.substr(0,2);
	int m = stoi(month) - 1;
	string date = input.substr(3,2);
	string year = input.substr(6,4);
	
	cout << months[m] << " " << date << ", " << year << endl;
	
	return 0;
}