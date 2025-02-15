#include<iostream>
using namespace std;

int sumParamaterised(int sum,int n){ // we are using extra variable to print the number
    if(n==0)
        return sum;
    sum = sum + n;
    int val = sumParamaterised(sum, n - 1);
    
}

int main(){
    int n = 6;
    int val = sumParamaterised(0,n);
    cout << val;
}