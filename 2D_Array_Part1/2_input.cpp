#include<iostream>
using namespace std;

int main(){
    int m;
    cout << "Enter the numbers of rows:  ";
    cin >> m;
    int n;
    cout << "Enter the numbers of column:  ";
    cin >> n;

    int arr[m][n];

    cout << "Enter the element of array : ";
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            cin >> arr[i][j];
        }
    }

    cout << "your array : ";
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            cout << arr[i][j]<<" ";
        }
        cout << endl;
    }
}