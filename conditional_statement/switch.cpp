// switch ((integral exprewwion))
// {
// case /* constant-expression */:
//     /* code */
//     break;

// default:
//     break;
// }

// write a program to input week number(1-7) and print day of week name using switch case.
#include<iostream>
using namespace std;
int main(){
    int x;
    cout << "enter day number : ";
    
    cout << x;
    switch (x){
        case 1:
            cout << "Monday";
            break;
        case 2:
            cout << "Tuesday";
            break;
        case 3:
            cout << "Wednesday";
            break;
        case 4:
            cout << "Thursday";
            break;
        case 5:
            cout << "Friday";
            break;
        case 6:
            cout << "Saturday";
            break;
        case 7:
            cout << "Sunday";
        default: 
            cout << "given number is not a week number";
            break;
        }
}