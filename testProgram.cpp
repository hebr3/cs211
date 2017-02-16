// writing on a text file
#include <iostream>
#include <fstream>
using namespace std;

int main () {
  string line;
  ifstream infile ("infile.txt");
  ofstream outfile ("outfile.txt");
  getline(infile, line);
  while (!infile.eof()) {
    outfile << line << endl;
	getline(infile, line);
  }
  infile.close();
  outfile.close();
  return 0;
}