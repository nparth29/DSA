#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "enter a number: ";
    cin >> n;
    bool flag = true; // true mean prime
    for (int i = 2; i <n;i++){ // if n = 2 it says 2 is prime
        if(n%i==0){
            flag = false; // false mean composite
            break;
        }
    }
    if (n==1){
        cout << "1 is neither prime nor composite!!!";
    }
    
    else if(flag==true){
        cout << n << " is prime number" << endl;
    }
    else cout << n << " is composit number" << endl;;
}