#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s = "abcdef";
    cout << "original string is: " << s<<endl;
    cout << s.substr(0)<<endl; // form index 0 to last index 
    cout << s.substr(1)<<endl;  // from index 1 to last one
    cout << s.substr(1,3) << endl;  // from index 1 and length of string is 3
    cout << s.substr(2,2)<<endl;  // from index 2 and length of string is 2

    // take the sting of even length and return the next half of the string
    string str;
    cout << "enter the string : ";
    getline(cin, str);
    int n = str.length();
    cout << str.substr(n / 2);

    return 0;
}


