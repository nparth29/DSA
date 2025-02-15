// absolute number of -x = x
#include<iostream>
using namespace std;
int main(){
    int x;
    cout << "enter a number : ";
    cin >> x;
    if(x>=0){
        cout << "absolute value of " << x << " is : " << x;
    }
    else{
        cout << "absolute value of " << x << " is " << (-x);
    }
}