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

string lineBreak = "-----------------------------------------------------------\n";

string FirstName(const string& info) {
	return info.substr(0, info.find(" ", 0));
}
string LastName(const string& info) {
	string cut;
	cut = info.substr(info.find(" ", 0)+1);
	return cut.substr(0, cut.find(" ", 0));
}
string LastFirstName(const string& info) {
	return LastName(info) + FirstName(info);
}

string Phone(const string& info) {
	return info.substr(info.size()-12);
}

/* SearchPhone */
string SearchPhone(const vector<string>& directory, const string criteria) {
	for (string person : directory) {
		if (person.find(criteria, 0) != person.npos) {
			return person + " is in directory\n";
		}
	}
	return "No Entries were found for " + Phone(criteria) + "\n";
}

/* Display
1) Display: This command displays all names/phone numbers in the phone directory in a neat table format.
*/
void Display(const vector<string>& directory) {
	cout << "Printing Current Directory:\n\n";
	
	for (string person : directory)
		cout << person << endl;
}

/* Add
2) Add firstName, lastName, phone: This command adds a new record to the directory. A new record contains a first name, last name and phone number. The program should check for duplicate entries. If the phone number already exists in the directory, then it should not be added again. If the phone number does not exist in the directory, the program should add the person name and phone number at the end of the directory.
*/
void Add(vector<string>& directory, string info) {
	cout << "Adding " << info << " to the directory:" << endl;
	
	// Check if info already exists in the directory
	for (string& person : directory) {
		if (person.find(Phone(info), 0) != person.npos) {
			cout << person + " is in the directory" << endl
				 << "This phone number already exists in directory" << endl
				 << "and was not added again to the directory" << endl;
			return;
		}
	}	
	
	//add record to the directory
	directory.push_back(info);
	
	cout << "No Entries were found for " 
		 << Phone(info) <<  endl
		 << "This entry was successfully added to the directory"
		 << endl;
}

/* Search
3) Search criteria: This command searches for a person by full name, partial name, or phone number. The program should search the directory for a given criteria. Any entries that match the string entered should be displayed. If no entry is found, the program must display a message that this record does not exist in the directory. For example, if the user enters “Garcia”, the program should display the following names from the list:
Joe Garcia         8583432009
Kevin Garcia    7605435622
*/
void Search(const vector<string>& directory, const string& criteria) {
	cout << "Searching for " << criteria << " in the directory:" << endl;
	
	// Initialize tmpDir as an empty vector of matches
	vector<string> tmpDir;
	
	// Push all of the strings that match criteria to tmpDir
	for (string person : directory) {
		if(person.find(criteria, 0) != person.npos)
			tmpDir.push_back(person);
	}

	// check if the tmpDir is empty
	if (tmpDir.size() == 0) {
		cout << "No entries were found for " << criteria << endl;
	} else {
		for (string person : tmpDir)
			cout << person << " is in the directory" << endl;
	}
};

/* Delete
4) Delete record: This command deletes an existing record specified by either a phone number or person name. The entry that matches the specified number/name should be deleted. If no matching entry is found, the program must display a message that this record does not exist in the directory. Note that deleting could be from any entry in the directory and not necessarily the last record.
*/
void Delete(vector<string>& directory, string criteria) {
	cout << "Deleting " << criteria << " from the directory:" << endl;
	
	// Initialize deleteLocation and index value
	int deleteLocation = -1;
	int index = -1;
	string deletedEntry;
	
	for (string person : directory){
		index++;
		if(person.find(criteria,0) != person.npos) {
			deleteLocation = index;
			deletedEntry = person;
		}
	}
	
	if (deleteLocation == -1)
		cout << "No Entries were found for " << criteria << endl;
	else {
		directory.erase(directory.begin()+deleteLocation);
		cout << deletedEntry << " is in the directory\nand was successfully deleted" << endl;
	}
}

/* Update
5) Update oldNum, newNum: This command updates a record by modifying an entry’s telephone number. The command specifies the old number that needs to be updated and the new number. The program searches for the entry containing the old phone number. If the number is not in the directory, the program displays a message that this number is not found. Otherwise, the entry that holds the old phone number should be updated with the new phone number.
*/
void Update(vector<string>& directory, string nums) {
	string oldNum = nums.substr(0,12);
	string newNum = nums.substr(13);
	
	cout << "Updating phone number " << oldNum << endl;
	
	// Initialize found flags
	int flag = 0;
	
	// Check each value in directory
	for (string &person : directory)
		if (person.find(oldNum,0) != person.npos) {
			person.replace(person.size()-12,person.size(),newNum);
			flag = 1;
		}
	
	if (flag == 0)
		cout << oldNum << " was not found in the directory" << endl << endl;
	
	if (flag != 0)
		cout << "You have successfully updated the phone number " << oldNum << endl;
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
			if (LastFirstName(directory[count]) > LastFirstName(directory[count+1])) {
				temp = directory[count];
				directory[count] = directory[count+1];
				directory[count+1] = temp;
				swap = true;
			}
		}
	} while (swap);
	
	cout << "Directory successfully sorted" << endl;
}

/* Save
7) Save: This command saves the data in an output file “Phones.txt”.
*/
void Save(const vector<string>& directory, const string output) {
	// Initialize and open the outputFile
	ofstream outputFile;
	outputFile.open(output);
	
	for (string person : directory)
		outputFile << person << endl;
	
	// Close the outputfile
    outputFile.close();
	
	cout << "Data successfully stored in " 
		 << output << endl;
}

/* InputData
*/
vector<string> InputData(vector<string>& directory, const string& data) {
	// Initialize and open inputfile
	ifstream inputFile;
	inputFile.open(data);
	
	// Load the initial values into the directory from data.txt
	while(!inputFile.eof()) {
		// Initialize and load tmp variable, then push to directory
		string tmp;
		getline(inputFile, tmp);
		
		directory.push_back(tmp);
	}
	
	// Close the inputFile
	inputFile.close();
	
	return directory;
}

/* InputTransaction */
void InputTransaction(vector<string>& directory) {
	cout << "Please enter a transaction file to process\n";
	
	// Initialize variable and open corresponding file
	string input;
	cin >> input;
	cout << endl;
	
	ifstream transactFile;
	transactFile.open(input);
	
	// Start a while loop to read the values from the file
	while (!transactFile.eof()) {
		// Initialize a string to hold the getline value and find the first whitespace
		string line = "";
		getline(transactFile, line);
		//line.erase(line.size()-1);
		int p = line.find(" ", 0);
		
		string cmd = "", arg = "";
		if (p != line.npos) {
			cmd = line.substr(0, p);
			arg = line.substr(p+1);
		} else {
			cmd = line;
			arg = "nothing";
		}
		
		//cout << "cmd > " << cmd << endl;
		//cout << "arg > " << arg << endl;
		//cout << "line > " << line << endl;
		
		if (cmd == "display")
			Display(directory);
		else if (cmd == "add")
			Add(directory, arg);
		else if (cmd == "search")
			Search(directory, arg);
		else if (cmd == "delete")
			Delete(directory, arg);
		else if (cmd == "update")
			Update(directory, arg);
		else if (cmd == "sort")
			Sort(directory);
		else if (cmd == "save")
			Save(directory, "phonesOut.txt");
		else
			cout << cmd << " is broken" << endl;
		
		cout << lineBreak;
	}
	transactFile.close();
}

int main() {
	// initialize the directory as an empty vector of strings
	// and then the data into the directory from "data.txt"
	vector<string> directory;
	InputData(directory, "data.txt");
	
	// Print header and ask for the name of the transaction file
	cout << endl << lineBreak
		 << " Welcome to the CSUSM phone directory!"
		 << endl << lineBreak;

	InputTransaction(directory);
	
	return 0;
}
