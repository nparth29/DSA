#include<iostream>
using namespace std;


int main(){
    //fibonacci 
    //  ->>  1  1  2  3  5  8  13  21  34  55
    // term->1  2  3  4  5  6  7  8  9
    int a = 1;
    int b = 1;
    int sum = 0, n;
    cout << "enter a number : ";
    cin >> n;
    for (int i = 1; i <= n-2; i++)
    {
        sum = a + b;
        a = b;
        b = sum;
    }
    // if(n==1 || n ==2)
    //     cout << 1;
    // else
    //     cout << sum;
    cout << b;
}