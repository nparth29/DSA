#include<iostream>
using namespace std;

int printUsingExtraVariable(int sum,int n){ // we are using extra variable to print the number
    if(n==0)
        return;
    sum = sum + n;
    int val = printUsingExtraVariable(sum, n - 1);
    return val;
}

int main(){
    int n = 6;
    int val = printUsingExtraVariable(0,n);
    cout << val;
}