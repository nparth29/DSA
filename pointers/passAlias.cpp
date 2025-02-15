#include<iostream>
using namespace std;

void swap(int &a, int &b){ // pas by reference
    int temp = a;
    a = b;
    b = temp;
    return;
}

int main(){
    int a = 8, b = 6;
    cout <<"before swap: "<< a << " " << b<<endl;

    swap(a, b);
    cout <<"after swap: "<< a << " " << b;
}