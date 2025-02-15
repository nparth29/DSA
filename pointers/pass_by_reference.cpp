#include<iostream>
using namespace std;

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
    return;
}

int main(){
    int a = 8, b = 6;
    cout <<"before swap: "<< a << " " << b<<endl;

    swap(&a, &b);
    cout <<"after swap: "<< a << " " << b;
}