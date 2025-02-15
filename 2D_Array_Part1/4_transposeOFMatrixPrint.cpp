#include <iostream>
using namespace std;

int main() {
    int m;
    cout << "Enter the number of rows: ";
    cin >> m;
    int n;
    cout << "Enter the number of columns: ";
    cin >> n;

    int arr[m][n];

    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    cout << endl << "Your array: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Printing the transpose (column-wise printing)
    cout << endl << "Transpose of the array (column-wise):" << endl;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}
