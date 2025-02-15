#include<iostream>
#include<string>
using namespace std;

int main(){
    string name;
    cout << "enter the string : ";
    getline(cin, name);
    cout << name;
    name[1] = '0';
    cout << endl
         << name;
    // hence the string are mutable in cpp but in java string is not mutable;
    
}