#include<iostream>
using namespace std;

int main(){
    cout << "no of rows  ";
    int n;
    cin >> n;
    // we will use extra variable to print contineous numbers
    int k = 1;
    

    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= i;j++){
            cout << k<< " ";
            k++;
        }
        cout << endl;
    }
}