#include<iostream>
using namespace std;

//       1  2  3  4
//   1   *  *  *  *
//   2   *  *  *
//   3   *  *
//   4   *

//number of stars = n+1 -i(i mean number of rows)

int main(){
    cout << "enter number of rows: ";
    int r;
    cin >> r;
    
    for (int i = 1; i <= r;i++){
        for (int j = 1; j<= r+1-i;j++){
            cout << "*";
        }
        cout << endl;
        
    }
}