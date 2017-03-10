// Henry Brooks
// cs211

// Specification file for the Mortgage class.
#ifndef MORTGAGE_H
#define MORTGAGE_H

// Mortgage class declaration.

class Mortgage {
	private:
		double loanAmount;
		double rate;
		double years;
	public:
		Mortgage();					// Default constructor
		void setLoan(double);		// Setters
		void setRate(double);
		void setYears(double);
		double getLoan() const;		// Getters
		double getRate() const;
		double getYear() const;
		double getMonthlyPayment();
};
#endif
