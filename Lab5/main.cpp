// Henry Brooks
// CS211

/*
Lab 5
______________________________________________________________________________

The purpose of this lab is to practice working with basic classes.
______________________________________________________________________________
 
Design a class Mortgage that is used to determine the monthly payment on a home mortgage.
The class should contain at least the following private attributes:
loanAmount: the dollar amount of the loan
rate: the annual interest rate
years: the number of years of the loan.
 
The class should have a default constructor as well as other public member functions to:
set the loan amount, interest rate, and number of years of the loan
display the loan amount, interest rate, and number of years of the loan
compute the monthly payment amount and total amount paid to the bank at the end of the loan period. The monthly payment, monthlyPay, with interest compounded monthly can be calculated as follows: 

monthlyPay = (loanAmount * term * rate/12) / (term -1)

Where term = (1 + rate/12) 12*years
compute the total amount paid to the bank by the end of the loan period
 
Your main program should ask the user for the loan information and display the monthly payment and total amount paid by the end of the loan period.
 
A sample output is shown below:
Enter the loan amount in dollars: 500000
Enter the annual interest rate in decimal form: 0.0275
Enter the length of the loan in years: 30
Monthly payment: $2041.21
Total payback: $734834.13
   
Note:
You must separate your files into .cpp and .h file.
Input validation: you should do not accept negative numbers for any of the loan values
*/

#include <iostream>
#include "Mortgage.h"	// Needed for Mortgage class
using namespace std;

int main() {
	Mortgage test;	// Define an instance of the Mortgage class
	double loan, rate, years;
	// Get the Mortgage values
	cout << "Enter the loan amount in dollars: ";
	cin >> loan;
	test.setLoan(loan);
	
	cout << "Enter the annual interest rate in decimal form: ";
	cin >> rate;
	test.setRate(rate);
	
	cout << "Enter the length of the loan in years: ";
	cin >> years;
	test.setYears(years);
	
	// Display info
	double monthly = test.getMonthlyPayment();
	
	cout << "Monthly payment: $" <<monthly << endl;
	cout << "Total payback: $" << monthly * 12 * years << endl;
	
	return 0;
}