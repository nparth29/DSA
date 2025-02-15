// Take positive integer as input and tell if it is a three digit number or not.

#include<iostream>
using namespace std;
int main(){
    cout << "Enter a number : ";
    int x;
    cin >> x;
    if(x>99 && x<100){
        cout << "given number is three digit number...";
    }
    else{
        cout << "not a three digit number";
    }
}