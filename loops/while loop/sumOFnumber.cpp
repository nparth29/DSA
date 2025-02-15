#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "ente a number: ";
    cin >> n;
    int temp = n;
    int rem;
    int sum = 0;
    while(temp>0){
        rem = temp % 10;
        sum = sum + rem;
        temp /= 10;
        
    }
    cout << "the sum of the number " << n << " is :" << sum;
}