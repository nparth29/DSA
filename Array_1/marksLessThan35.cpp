// given an array of marks of students, if the marks of any student is less than 35
// print ists roll number. { roll number here refer to the index of the array}
#include<iostream>
using namespace std;

int main(){
    int marks[6]; 
    // input
    for (int i = 0; i <= 5;i++){
        cin >> marks[i];
    }

    // output
    for (int i = 0; i <= 5;i++){
        if(marks[i]<35)
            cout << i << " ";
    }
}