#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main(){
    string str = "I hate my life";
    stringstream ss(str);
    string temp;

    while(ss>>temp){
        cout << temp << endl;
    }
}