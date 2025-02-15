#include<iostream>
using namespace std;

int main(){
    char ch;
    cout << "enter a character: ";
    cin >> ch;
    if(ch>='a' && ch <= 'z'){
        cout << "the given character lower case alphabet ";
    }
    if(ch>='A' && ch <= 'Z'){
        cout << "the given character upper case alphabet ";
    }
}