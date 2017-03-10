// Henry Brooks
// CS211
// brook057@cougars.csusm.edu
// 02-08-2017

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

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

string SearchPhone(const vector<string>& directory, const string criteria) {
	for (string person : directory) {
		if (person.find(criteria, 0) != person.npos) {
			return person + " is in directory\n";
		}
	}
	return "No Entries were found for " + Phone(criteria) + "\n";
}

void Display(const vector<string>& directory) {
	cout << "Printing Current Directory:\n\n";
	
	for (string person : directory){
		string first = FirstName(person);
		string last = LastName(person);
		string phone = Phone(person);
		
		cout << left << setw(10) << first
			 << setw(10) << last 
			 << phone << endl;
	}
}

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
	
	// If the info is not found then add record to the directory
	directory.push_back(info);
	cout << "No Entries were found for " 
		 << Phone(info) <<  endl
		 << "This entry was successfully added to the directory"
		 << endl;
}

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

vector<string> InputData(vector<string>& directory, const string& data) {
	// Initialize and open inputfile
	ifstream inputFile;
	inputFile.open(data);
	
	cout << inputFile.good();
	
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
	// and then add the data into the directory from "data.txt"
	vector<string> directory;
	InputData(directory, "data.txt");
	
	// Print header and ask for the name of the transaction file
	cout << endl << lineBreak
		 << " Welcome to the CSUSM phone directory!"
		 << endl << lineBreak;

	InputTransaction(directory);
	
	return 0;
}
