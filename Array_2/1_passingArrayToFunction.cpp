#include<iostream>
using namespace std;
// if we pass an array through function we tectionally passing the address of the array 
//      address mean the first element address  
void display(int a[], int size){  // intstead of int a[] we can use int *a coz its a pointer 
    for (int i = 0; i < size;i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return;
}

void change(int b[], int size){
    b[0] = 12;
    return;
}

int main(){
    int arr[] = { 1,2,3,4,5,6,7};
    int size = sizeof(arr) / sizeof(int);
    display(arr, size);
    change(arr, size);
    display(arr, size);
    //  hence it is pass by reference 
} 