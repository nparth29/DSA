#include<iostream>
using namespace std;

int fact(int x){
    int f = 1;
    for (int i = 2; i <= x;i++){
        f *= i;
       
    }
     return f;
}

int combination(int n, int r){
    int nCr = fact(n) / (fact(r) * fact(n-r));
    return nCr;
}

int main()
{
    int n;
    cout << "enter the value of n: ";
    cin >> n;
    int r;
    cout << "enter the value of r: ";
    cin >> r;
    int nCr = combination(n, r);
    cout << nCr;
}