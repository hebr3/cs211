// Henry Brooks
// CS211 
// brook057@cougars.csusm.edu
// 02/10/2017

/*
Program 1:
Write a program that reads a sentence as an input and converts each word to "Pig Latin".
To convert a word to Pig Latin, you remove the first letter and place that letter at the end of the word. Then you append the string "ay" to the word.
You may use the following sentence to test your code:
English: I slept most of the night
Pig Latin: Iay leptsay ostmay foay hetay ightnay
*/
#include <iostream>
#include <string>

using namespace std;

void Translate(const string& word) {
	string first = word.substr(0,1);
	string rest = word.substr(1);
	cout << rest + first + "ay ";
}

int main () {
	cout << "Please enter a sentence to convert\n";
	
	string lineIn;
	string tempWord;
		
	getline(cin, lineIn);
	
	for(int count = 0; count < lineIn.size(); count++) {
		if (lineIn.compare(count, 1, " ") == 1) {
			tempWord += lineIn.at(count);
		} else {
			Translate(tempWord);
			tempWord = "";
		}
	}
	
	Translate(tempWord);
	cout << endl;
	
	return 0;
}