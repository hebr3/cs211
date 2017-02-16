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

using namespace std;

/* Display
1) Display: This command displays all names/phone numbers in the phone directory in a neat table format.
*/
void Display(const vector<string>& directory) {
	for(string info : directory)
		cout << info << endl;
}

/* Add
2) Add firstName, lastName, phone: This command adds a new record to the directory. A new record contains a first name, last name and phone number. The program should check for duplicate entries. If the phone number already exists in the directory, then it should not be added again. If the phone number does not exist in the directory, the program should add the person name and phone number at the end of the directory.
*/
void Add(vector<string>& directory, string firstName, string lastName, string phone) {
	// Initialize variables
	string tmp;
	
	// Append values to tmp string
	tmp.append(firstName);
	
	while(tmp.size() < 10)
		tmp += " ";
	
	tmp.append(lastName);
	
	// Append whitespace until length of tmp is 20
	while(tmp.size() < 20)
		tmp += " ";
	
	// Append phone number
	tmp.append(phone);
	
	cout << "Adding " << firstName << " " << lastName << " " << phone
		 << " to the directory:\n";
	
	//add record to the directory
	directory.push_back(tmp);
	
	cout << "---------------------------------------------------------\n";
}

/* Search
3) Search criteria: This command searches for a person by full name, partial name, or phone number. The program should search the directory for a given criteria. Any entries that match the string entered should be displayed. If no entry is found, the program must display a message that this record does not exist in the directory. For example, if the user enters “Garcia”, the program should display the following names from the list:
Joe Garcia         8583432009
Kevin Garcia    7605435622
*/
void Search(vector<string>& directory, string criteria) {
	// Initialize tmpDir, an emptry vector of matches
	vector<string> tmpDir;
	
	// Push all of the strings that match criteria to tmpDir
	for (string person : directory) {
		if(person.find(criteria,0) != person.npos)
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
void Delete(vector<string>& directory, string criteria) {
	// Initialize deleteLocation and index value
	int deleteLocation = -1;
	int index = -1;
	
	for (string person : directory){
		index++;
		if(person.find(criteria,0) != person.npos)
			deleteLocation = index;
	}
	
	if (deleteLocation == -1)
		cout << "\"" << criteria << "\" was not found in the directory" << endl;
	else {
		directory.erase(directory.begin()+deleteLocation);
	}
}

/* Update
5) Update oldNum, newNum: This command updates a record by modifying an entry’s telephone number. The command specifies the old number that needs to be updated and the new number. The program searches for the entry containing the old phone number. If the number is not in the directory, the program displays a message that this number is not found. Otherwise, the entry that holds the old phone number should be updated with the new phone number.
*/
void Update(vector<string>& directory, string oldNum, string newNum) {
	// Initialize found flags
	int flag = 0;
	
	// Check each value in directory
	for (string &person : directory)
		if (person.find(oldNum,0) != person.npos) {
			person.replace(20,28,newNum);
			flag = 1;
		}
	
	if (flag == 0)
		cout << "\"" << oldNum << "\" was not deleted from the directory" << endl << endl;
}

/* Sort
6) Sort: This command sorts the directory alphabetically by last name. If two records have the same family names, they are sorted by first names.
*/
void Sort(vector<string>& directory) {
	// Initialize temp string, and swap flag;
	bool swap;
	string temp;
	
	do {
		swap = false;
		for (int count = 0; count < directory.size()-1; count++) {
			if (directory[count].substr(10,10) > directory[count+1].substr(10,10)) {
				temp = directory[count];
				directory[count] = directory[count+1];
				directory[count+1] = temp;
				swap = true;
			}
		}
	} while (swap);
}

/* Save
7) Save: This command saves the data in an output file “Phones.txt”.
*/
void Save(const vector<string>& directory) {
	// Initialize and open the outputFile
	ofstream outputFile;
	outputFile.open("Phones.txt");
	
	for (string person : directory)
		outputFile << person << endl;
	
	// Close the outputfile
    outputFile.close();
}

/* Input
*/
vector<string> Input(vector<string>& directory, const string& data) {
	// Initialize and open inputfile
	ifstream inputFile;
	inputFile.open(data);
	
	// Load the initial values into the directory from data.txt
	while(!inputFile.eof()) {
		// Initialize variables
		string tmp, firstName, lastName, phone;
		
		// move values to variables
		inputFile >> firstName >> lastName >> phone;
		
		// Append values to tmp string
		tmp.append(firstName);
		
		while(tmp.size() < 10)
			tmp += " ";
		
		tmp.append(lastName);
		
		// Append whitespace until length of tmp is 20
		while(tmp.size() < 20)
			tmp += " ";
		
		// Append phone number
		tmp.append(phone);
		
		// add tmp Record to directory
		directory.push_back(tmp);
	}
	
	// Close the inputFile
	inputFile.close();
	
	return directory;
}

int main() {
	// initialize directory, an empty vector of strings
	vector<string> directory;

	Input(directory, "data.txt");
	
	// Print header and ask for the name of the transaction file
	cout << "---------------------------------------------------------" << endl
		 << "Welcome to the CSUSM phone directory!" << endl
		 << "---------------------------------------------------------" << endl
		 << "Please enter a transaction file to process" << endl << endl;
	
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