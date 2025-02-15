#include<iostream>
#include<string>
using namespace std;

int main(){


    string name;
    cout << "Enter your full name: ";
    getline(cin, name);  // Reads the full line, including spaces
    cout << "Your full name is: " << name << endl;

    string str = "naman";   // size is 6 => 5+1 (null char)
    cout << str<<endl;
    

    string s;
    cout << "enter the string : ";     // do not give the space while input
    cin >> s;
    cout <<"your string is : "<< s;
    // if you are using cin for input => do not use space other wise the next word is not store in that variable
    cout << endl;

}