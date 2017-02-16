// Example program
#include <iostream>
#include <string>
using namespace std;

int main ()
{
    string name1, name2;
    
    // get a name.
    cout << "Enter a name (last name first): ";
    getline(cin, name1);
    
    //get another name
    cout << "Enter another name: ";
    getline(cin, name2);
    
    //display them in alphabetical order.
    cout << "Here are the names sorted alphabetically:\n";
    
    if (name1 < name2)
        cout << name1 << endl << name2 << endl;
    else if (name2 < name1)
        cout << name2 << endl << name1 << endl;
    else cout << "You entered the same name twice!\n";
    return 0;
}