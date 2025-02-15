#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "enter your marks b/w 0 to 100: ";
    cin >> n;

    if(n>=91)
        cout << "excelent";
    else if (n>=80)
        cout << "good";
    else if (n>= 71){
        cout << "fair";
    }
    else if (n>=51)
        cout << "can do better";
    else if(n>=41)
        cout << "average";
    else
        cout << "fail";
}