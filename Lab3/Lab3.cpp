// Henry Brooks
// 2/6/2017
// CS 211
/* 
Write a program that creates a vector of strings called V. Vector V grows and shrinks as the user processes the transactions from a data file called �data.txt�. The transaction file can only include three commands: Insert, Delete and Print. With Insert command, you get two more information, the information you need to insert and the position it should be inserted. With Delete, you get one more information that indicates which element (index) should be deleted. Print command means the content of the vector should be printed on the screen. For example, you may have the following information in your file:

Insert Hello 4

Delete 5

Print
 

The first line indicates that The word �Hello� should be inserted in V[4]. Of course you should check if this insert is possible. This insert is possible if the position you are attempting to insert the element is not beyond the size of the vector.

The second line means V[5] should be removed. Again this operation should only be allowed if the index is not beyond the current size of the vector.

Test your program with the following transaction file:


Insert Total 0

Insert Normal 0

Insert Perfect 1

Insert Program 1

Insert Book 2

Print

Insert Perfect 5

Delete 1

Delete 7

Insert Money 2

Delete 3

Print

Note: Each command must be implemented in a separate function.

*/
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void print(const vector<string>& vec) {
  for (string str : vec)
    cout << str << endl;
}

void insert(vector<string>& vec, string str, int index) {
  // Check that index is inside of the string
  if (index > vec.size()) {
    cout << "Cannot Insert " << index << endl;
    return;
  }
	
  // Insert if able
  vec.insert(vec.begin()+index, str);
}

void del(vector<string>& vec, int index) {
  // Check index
  if (index > vec.size()) {
    cout << "Cannot Delete " << index << endl;
    return;
  }
			
  // Delete value at index
  vec.erase(vec.begin()+index);
}

int main() {
  // Initialize V to emtpy vector of strings
  vector<string> V;
	
  // Initialized and open inputFile
  ifstream inputFile;
  inputFile.open("data2.txt");
	
  // Start a loop to read from file
  while (inputFile) {
    // Initialize tmp and read next command
    string cmd;
    inputFile >> cmd;
		
    if (cmd == "Insert") {
      // Initialize variables for string and index
      string str;
      int index;
	
      // Assign values to string and index form file
      inputFile >> str;
      inputFile >> index;
	
      // Send to function
      insert(V, str, index);
    }
		
    if (cmd == "Delete") {
      // Initialize variables for index
      int index;
			
      // assign values to index
      inputFile >> index;
			
      // Pass parameters to function
      del(V, index);
    }
		
    if (cmd == "Print") {
      print(V);
    }
    
  }
  
  return 0;
}
