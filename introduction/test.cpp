#include<iostream>
using namespace std;

int main(){
    cout << "hello world \n";
    cout << endl;

    // to print in next line cout << "hello world";
    cout << "hello CW" << endl<<"hello parth"<<endl;

    cout << "hello PW";
    cout << endl;
    int x = 5;
    x += 5;   
    cout << x<<endl;
    cout << endl;
    

    // imp :
    cout << 2.0<<endl; // output is 2 not 2.0
    float a = 5.0;
    cout << a<<endl;  // output is 5 not 5.0
    cout << endl;

    // bool give output in 0 and 1 for false and true respectively 
    bool flag = 1; // or true instead of one
    cout << flag << endl;
    bool sys = 20;
    cout << sys << endl;
    bool que = -11;
    cout << que << endl;
    bool _flag = false;
    cout << _flag << endl;
    return 0;
}