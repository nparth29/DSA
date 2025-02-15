#include<iostream>
using namespace std;
int main(){
    int x;
    int y;
    int *ptr1 = &x;
    int *ptr2 = &y;

    // taking input using pointer 
     cout << "Ente the first number :  ";
     cin >> *ptr1;
    cout << "Enter the second number : ";
    
    cin >> *ptr2;
    int sum = *ptr1 + *ptr2;
    cout << sum<<endl<<endl;

}
   