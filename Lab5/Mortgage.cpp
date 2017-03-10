// Henry Brooks
// CS211

// Implementation file for the Mortgage class.
#include "Mortgage.h"	// Needed for the Mortgage class
#include <iostream>		// Needed for cout
#include <cstdlib>		// Needed for the exit function
#include <math.h>		// Needed for the pow function
using namespace std;

// Mortgage default constructor
Mortgage::Mortgage() {
	double loanAmount = 0;
	double rate = 0;
	double years = 0;
}

// setLoan()
void Mortgage::setLoan(double loan) {
	if (loan >= 0)
		loanAmount = loan;
	else {
		cout << "Invalid loan amount\n";
		exit(EXIT_FAILURE);
	}
}

// setRate()
void Mortgage::setRate(double rat) {
	if (rat >= 0)
		rate = rat;
	else {
		cout << "Invalid rate\n";
		exit(EXIT_FAILURE);
	}
}

// setYears()
void Mortgage::setYears(double time) {
	if (time >= 0)
		years = time;
	else {
		cout << "Invalid time\n";
		exit(EXIT_FAILURE);
	}
}

// getLoan
double Mortgage::getLoan() const {
	return loanAmount;
}

// getRate
double Mortgage::getRate() const {
	return rate;
}

// getYear
double Mortgage::getYear() const {
	return years;
}

// getMonthlyPayment()
double Mortgage::getMonthlyPayment() {
	double term;
	term = pow((1 + rate / 12), 12*years);
	return (loanAmount * term * (rate / 12)) / (term - 1);
}

// getTotalPayback()
//double getTotalPayback() {}