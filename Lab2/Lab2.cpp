// read a list of integers from inputFile until end-of-file
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  // Initialized empty vector
  vector<int> V;
	
  // Initialized holding variable
  int holding;
	
  // Initialized inputFile
  ifstream inputFile;
  inputFile.open("data.txt");
	
  // Load first element of inputFile into holding
  inputFile >> holding;
  
  // While inputFile is sending results
  while (inputFile) {
    V.push_back(holding);
    inputFile >> holding;
  }
	
  // Close inputfile
  inputFile.close();
	
	
  cout << endl 
       <<"Please enter a key to search for in data3.txt: ";
	
  // Initialize key and search flag
  int key;
  bool found = false;
	
  // Get user input
  cin >> key;
	
  // Check all values in vector
  for (int val : V) {
    cout << val;
    if (val == key) {
      cout << " <--" << endl;
      found = true;
    } else {
      cout << endl;
    }
  }
	
  cout << endl;
		
  // If the found flag is true output positive result
  if (found) {
    cout << "The key was found" << endl << endl;
  } else {
    cout << "The key was not found" << endl;
  }
	
}
