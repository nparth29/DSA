#include<iostream>
using namespace std;
int main(){
    int x = 4;
    int *p = &x; // &x is the adress of x and it get stored in pointer p
    cout << &x << endl;
    cout << p;
}