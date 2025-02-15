#include<iostream>
using namespace std;

void fun(int x = 7, int y = 8){
    cout << "default value of x is : " << x<<endl;
    cout << "default value of y is : " << y<<endl;
    cout << endl;
}

void hii(int x = 7, int y = 8){
    cout << "actual value of x is : "<<x <<endl;
    cout << "actual value of y is : "<<y <<endl;
    cout << endl;
}

void bro(int x = 7,int y = 8){
    cout << "actual value of x is : "<<x <<endl;
    cout << "default value of y is : "<<y <<endl;
}

int main(){
    fun();
    hii(3, 4);
    bro(3);
}