// input a string of length greater than 5 and reverse the substring form position 2 to 5 using inbuilt function 

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str4;
    cout << "enter the string : ";
    getline(cin,str4);
    cout <<"original string is : "
         << str4
         <<endl
         << "after reversing the part of string : ";
    reverse(str4.begin() + 1, str4.begin() + 5); // positon 2 mean index 1
    cout << str4;
    return 0;
}


