// Henry Brooks
// CS211 
// brook057@cougars.csusm.edu

/*
Program 1:

Your favorite shoe store is having a sale – all pairs of shoes are 35% off! Write a program that reads shoe prices in stock at the local store from an input file, shoe.txt. Each row in the file contains a shoe serial number and price. Calculate the sale price of every pair of shoes, and what the final cost of the shoes is when the sales tax is applied to the discounted price. The calculated data must be saved in an output file, shoeSale.txt.

You MUST use a named constant for both the tax rate (8.5%) and discount rate (35%). Since the results displayed are monetary values, your output must be displayed with two decimal places of precision. Be sure decimals “line up” when you output the information.

Sample input file:
234019 75.00
234490 124.99
347269 50.00
239801 149.99
487241 99.99
982111 175.00

Sample output file:
234019 52.89
234490 88.15
347269 35.26
239801 105.78
487241 70.51
982111 123.41
*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// init constants
const double TAX_RATE = 0.085;
const double DISCOUNT_RATE = 0.35;

int main () {
  // initialize files
  ifstream inputFile;
  inputFile.open("shoe.txt");
  
  ofstream outputFile;
  outputFile.open("shoeSales.txt");
  
  // init variables
  int serialNumber;
  double price,
         discount,
	 discountedPrice,
	 saleTax,
	 final;
  
  if (inputFile.is_open()) {
    while (inputFile.good()) {
      // Pull info off file
      inputFile >> serialNumber >> price;
      
      // Convert price to final price
      discount = price * DISCOUNT_RATE;
      discountedPrice = price - discount;
      saleTax = discountedPrice * TAX_RATE;
      final = discountedPrice + saleTax;
      
      // Output final serialNumber and price to file
      outputFile << serialNumber
                 << setw(8) << setprecision(2)
                 << fixed << showpoint << right 
                 << final << endl;
    }
    
    // Close the file
    outputFile.close();
  }
  else {
    cout << "Unable to open file";
  }

  return 0;
}
