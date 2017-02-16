// Henry Brooks
// CS211
// brook057@cougars.csusm.edu
// 02-08-2017

/*
Summary:
Write a program that maintains a telephone directory. The Telephone directory keeps records of people’s names and the corresponding phone numbers.
The program should read an unknown number of names and phone numbers from a file “data.txt” and store them in a vector of strings. Each line in the input file contains a first name, last name and phone number in the following format xxx-xxx-xxxx. For example, you may use the following data in your input file:
“data.txt”
Joe Garcia 858-343-2009
Amelia Perez 617-255-0987
Bob Haynes 858-765-1122
Tim Ducrest 760-877-1654     
Kevin Garcia 760-543-5622
Suzy Walter 858-190-2307
Fang Yi 619-677-1212
Robert James 619-909-3476    
Mary Palmer 760-435-2086
The program should then ask the user for a transaction file name to load and process. The transaction file contains commands that perform typical directory functionalities. The list includes the following commands:
1) Display: This command displays all names/phone numbers in the phone directory in a neat table format.
 
2) Add firstName, lastName, phone: This command adds a new record to the directory. A new record contains a first name, last name and phone number. The program should check for duplicate entries. If the phone number already exists in the directory, then it should not be added again. If the phone number does not exist in the directory, the program should add the person name and phone number at the end of the directory.
 
3) Search criteria: This command searches for a person by full name, partial name, or phone number. The program should search the directory for a given criteria. Any entries that match the string entered should be displayed. If no entry is found, the program must display a message that this record does not exist in the directory. For example, if the user enters “Garcia”, the program should display the following names from the list:
Joe Garcia         8583432009
Kevin Garcia    7605435622
 
4) Delete record: This command deletes an existing record specified by either a phone number or person name. The entry that matches the specified number/name should be deleted. If no matching entry is found, the program must display a message that this record does not exist in the directory. Note that deleting could be from any entry in the directory and not necessarily the last record.
 
5) Update oldNum, newNum: This command updates a record by modifying an entry’s telephone number. The command specifies the old number that needs to be updated and the new number. The program searches for the entry containing the old phone number. If the number is not in the directory, the program displays a message that this number is not found. Otherwise, the entry that holds the old phone number should be updated with the new phone number.
           
6) Sort: This command sorts the directory alphabetically by last name. If two records have the same family names, they are sorted by first names.
7) Save: This command saves the data in an output file “Phones.txt”. 
 
Note: Each command must be implemented in a separate function.
To test your code, you may load and process the following transaction file:
“trans1.txt”
add Mayssaa Sarkis 885-565-4567
add Julia Adams 456-343-2087
sort
add Michel Ducrest 215-456-2231
add Bryan James 215-456-2231
delete Amy James
delete 215-456-2231
update 456-343-2087 456-189-6554
add Dennis Lefleurt 334-543-8769
search Julia
search 543-456-2222
save
 
Once done, you need to submit the following:
A hard copy (printed copy) of the source code and output placed in a folder. You should hand in the folder during the first 5 minutes of the class when the homework is due. You lose 10% of the grade if you do not provide a complete folder.
An electronic copy of your source code and executable file (no output). You should place all source codes in a zipped folder and name it based on your first/last name and the assignment number. For example, JoeSmith-A1.zip. You should submit the zipped folder online through cougar website.
*/

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// initialize Record type
struct Record {
	string firstName;
	string lastName;
	string phone;
};

/* Display
1) Display: This command displays all names/phone numbers in the phone directory in a neat table format.
*/
void Display(const vector<Record>& directory) {
	for(Record person : directory)
		cout << person.firstName << "\t"
			 << person.lastName << "\t"
			 << person.phone << endl;
}

/* Add
2) Add firstName, lastName, phone: This command adds a new record to the directory. A new record contains a first name, last name and phone number. The program should check for duplicate entries. If the phone number already exists in the directory, then it should not be added again. If the phone number does not exist in the directory, the program should add the person name and phone number at the end of the directory.
*/
void Add(vector<Record>& directory, string firstName, string lastName, string phone) {
	// Initialize tmp record
	Record tmp = {firstName, lastName, phone};
	
	//add record to the directory
	directory.push_back(tmp);
}

/* Search
3) Search criteria: This command searches for a person by full name, partial name, or phone number. The program should search the directory for a given criteria. Any entries that match the string entered should be displayed. If no entry is found, the program must display a message that this record does not exist in the directory. For example, if the user enters “Garcia”, the program should display the following names from the list:
Joe Garcia         8583432009
Kevin Garcia    7605435622
*/
void Search(vector<Record>& directory, string criteria) {
	// Initialize tmpDir of matches
	vector<Record> tmpDir;
	
	// Push all of the Records that match criteria to tmpDir
	for (Record person : directory) {
		if (person.firstName == criteria || person.lastName == criteria || person.phone == criteria)
			tmpDir.push_back(person);
	}

	// check if the tmpDir is empty
	if (tmpDir.size() == 0) {
		cout << "\"" << criteria << "\" was not found in the directory" << endl;
		return;
	}

	// Display tmpDir
	Display(tmpDir);
};

/* Delete
4) Delete record: This command deletes an existing record specified by either a phone number or person name. The entry that matches the specified number/name should be deleted. If no matching entry is found, the program must display a message that this record does not exist in the directory. Note that deleting could be from any entry in the directory and not necessarily the last record.
*/
void Delete(vector<Record>& directory, string criteria){
	// Initialize deleteLocation and index value
	int deleteLocation = -1;
	int index = -1;
	
	for (Record person : directory){
		index++;
		if (person.firstName == criteria || person.lastName == criteria || person.phone == criteria)
			deleteLocation = index;
	}
	
	if (deleteLocation == -1) {
		cout << "\"" << criteria << "\" was not found in the directory" << endl;
	} else { 
		directory.erase(directory.begin()+deleteLocation);
	}
}

/* Update
5) Update oldNum, newNum: This command updates a record by modifying an entry’s telephone number. The command specifies the old number that needs to be updated and the new number. The program searches for the entry containing the old phone number. If the number is not in the directory, the program displays a message that this number is not found. Otherwise, the entry that holds the old phone number should be updated with the new phone number.
*/
void Update(vector<Record>& directory, string oldNum, string newNum) {
	// Initialize found flag
	int found = 0;
	
	// Check each value in directory
	for (Record &person : directory)
		if (person.phone == oldNum) {
			person.phone = newNum;
			found = 1;
		}
	
	if (found == 0)
		cout << "Old number: " << oldNum << endl
			 << "was not found in the directory" << endl << endl;
}

/* Sort
6) Sort: This command sorts the directory alphabetically by last name. If two records have the same family names, they are sorted by first names.
*/
void Sort(vector<Record>& directory) {
	// Initialize temp Record, and swap flag;
	bool swap;
	Record temp;
	
	do {
		swap = false;
		for (int count = 0; count < directory.size()-1; count++) {
			if (directory[count].lastName > directory[count+1].lastName) {
				temp = directory[count];
				directory[count] = directory[count+1];
				directory[count+1] = temp;
				swap = true;
			}
		}
	} while (swap);
}

/*
7) Save: This command saves the data in an output file “Phones.txt”.
*/
void Save(const vector<Record>& directory) {
	// Initialize and open the outputFile
	ofstream outputFile;
	outputFile.open("Phones.txt");
	
	for (Record person : directory)
		outputFile << setw(10) << left  
				   << person.firstName << setw(10)
				   << person.lastName
				   << person.phone << endl;
	
	// Close the outputfile
    outputFile.close();
}


int main() {
	// initialize the directory as an empty vector of records
	vector<Record> directory;

	// Initialized and open the inputFile "data.txt"
	ifstream inputFile;
	inputFile.open("data.txt");
	
	// Load the initial values into the directory from "data.txt"
	while(!inputFile.eof()) {
		// Initialize variables
		string firstName, lastName, phone;
		
		// move values to variables
		inputFile >> firstName >> lastName >> phone;
		
		// initialize tmp record
		Record tmp = {firstName, lastName, phone};
		
		// add tmp Record to directory
		directory.push_back(tmp);
	}
	
	// Close the inputFile
	inputFile.close();
	
	// Ask the user for the name of the transaction file
	cout << "Please enter the name of your transaction file: ";
	
	// Initialize and store the name of the transaction file
	string name;
	cin >> name;
	
	// Initialized and open transactFile
	ifstream transactFile;
	transactFile.open(name);
	
	// Start a loop to read from file
	while (transactFile) {
		// Initialize tmp and read next command
		string cmd;
		transactFile >> cmd;
		
		if (cmd == "add") {
			// Initialize string variables for firstName, lastName, and phone
			string first, last, phone;
			
			// Assign values to first, last, and phone
			transactFile >> first;
			transactFile >> last;
			transactFile >> phone;
			
			// Pass parameters to the function
			Add(directory, first, last, phone);
		}
		
		if (cmd == "delete") {
			// Initialize string variable for criteria
			string criteria;
			
			// assign values to criteria
			transactFile >> criteria;
			
			// Pass parameters to function
			Delete(directory, criteria);
		}
		
		if (cmd == "update") {
			// Initialize string variables for oldNum and newNum
			string oldNum, newNum;
			
			// assign values to criteria
			transactFile >> oldNum;
			transactFile >> newNum;
			
			// Pass parameters to the function
			Update(directory, oldNum, newNum);
		}
		
		if (cmd == "search") {
			// Initialize string variable for criteria
			string criteria;
			
			// assign values to criteria
			transactFile >> criteria;
			
			// Pass parameters to function
			Search(directory, criteria);
		}
				
		if (cmd == "display")
			Display(directory);
		
		if (cmd == "sort")
			Sort(directory);

		if (cmd == "save")
			Save(directory);
	}
	
	return 0;
}