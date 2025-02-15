//you have given a natrix of size nxn change this natrix into its transpose.

// #include<iostream>
// using namespace std;

// int main(){
//     int n;
//     cout << "Enter the nunbers of rows/column:  ";
//     cin >> n;

//     int arr[n][n];

//     cout << "Enter the elenent of array : "<<endl;
//     for (int i = 0; i < n;i++){
//         for (int j = 0; j < n;j++){
//             cin >> arr[i][j];
//         }
//     }

//     cout << "your array : "<<endl;
//     for (int i = 0; i < n;i++){
//         for (int j = 0; j < n;j++){
//             cout << arr[i][j]<<" ";
//         }
//         cout << endl;
//     }

//     // transpose :
//     for (int i = 0; i < n;i++){
//         for (int j = i; j < n;j++){
//             int temp = arr[i][j];
//             arr[i][j] = arr[j][i];
//             arr[j][i] = temp;
//         }
//     }

//     cout << "transpose array : "<<endl;
//     for (int i = 0; i < n;i++){
//         for (int j = 0; j < n;j++){
//             cout << arr[i][j]<<" ";
//         }
//         cout << endl;
//     }
// }

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of rows/columns: ";
    cin >> n;

    int arr[n][n];

    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "\nYour original array: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Transpose: swap arr[i][j] with arr[j][i] for i < j
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    cout << "\nTransposed array: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    

    return 0;
}
