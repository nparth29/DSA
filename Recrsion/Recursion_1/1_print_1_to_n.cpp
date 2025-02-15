#include<iostream>
using namespace std;

void printUsingExtraVariable(int i,int n){ // we are using extra variable to print the number
    if(i > n)
        return;
    cout << i << endl;
    printUsingExtraVariable(i + 1,n);
}

int main(){
    int n = 6;
    printUsingExtraVariable(1,n);
    
}