#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "enter number of rows : ";
    cin >> n;
    int nst = 1; // number of stars
    int nsp = n - 1; // number  of spaces
// ssss*
// sss***                 we can see no of space is always n -1 
// ss*****
// s*******
// *********

    for (int i = 1; i <= n;i++){
        // spaces
        for (int j = 1; j <= nsp;j++){
            cout << " ";
        }
        nsp--;
        // star
        for (int k = 1; k <= nst;k++){
            cout << "*";
        }
        nst += 2;
        cout << endl;
    }
}