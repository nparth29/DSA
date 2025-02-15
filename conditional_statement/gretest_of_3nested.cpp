// using nested 

#include<iostream>
using namespace std;

int main(){
    int a, b, c;
    cout << "enter first number: " << endl;
    cin >> a;

    cout << "enter second number: " << endl;
    cin >> b;

    cout << "enter third number: " << endl;
    cin >> c;

    if(a>b){
        if(a>c){
            cout << a << " is the largest ";
        }
        else{
            cout << c << " is largest";
        }
    }
    else{
        if(b>c){
            cout << b << " is largest";
        }
        else{
            cout << c << " c is largest";
        }
    }
}
