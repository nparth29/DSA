#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "ente a number: ";
    cin >> n;
    int rem,temp = n;
    int reverse =0;
    while(temp>0){
        rem = temp % 10;
        reverse = reverse * 10 + rem;
        temp = temp / 10;
    }
    cout << "the reverse of the number is : " << reverse;
}