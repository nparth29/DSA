#include<iostream>
using namespace std;

    //       1   2   3   4   5

    // 1     1
    // 2     1   3
    // 3     1   3   5
    // 4     1   3   5   7
    // 5     1   3   5   7   9
          

int main(){
    cout << "enter number of rows: ";
    int r;
    cin >> r;
    
    for (int i = 1; i <= r;i++){
        int a = 1;
        for (int j = 1; j<=i;j++){
            cout << a;
            a += 2;
        }
        cout << endl;
        
    }
}