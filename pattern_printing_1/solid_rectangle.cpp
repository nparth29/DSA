#include<iostream>
using namespace std;
int main(){
    cout << "enter number of rows: ";
    int rows;
    cin >> rows;
    int column;
    cout << "enter number of columb : ";
    cin >> column;

    for (int i = 1; i <= rows;i++){
        for (int j = 1; j<= column;j++){
            cout << "*";
        }
        cout << endl;
    }
}