#include<iostream>
using namespace std;

void print(int n){ // we are using extra variable to print the number
    if(n == 0)
        return;
    print(n-1);
    cout << n << endl;
    
}

int main(){
    int n = 6;
    print(n);
    
}