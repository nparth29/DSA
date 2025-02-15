#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "ente a number: ";
    cin >> n;
    int a = n;
    int count = 0;
    while(n>0){
        n /= 10;
        count++;
    }
    
    if(a==0)
        cout << "number of digit is 1";
    else 
        cout <<"the number of digit is :"<<count;
}