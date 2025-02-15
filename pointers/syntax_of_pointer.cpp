#include<iostream>
using namespace std;
int main (){
    int x = 5, y = 10; // no issue here
//     int *p = &x, q = &y;  --->> give an erroe
    int *p = &x, q = y; // no error
 }  