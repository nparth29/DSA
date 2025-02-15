/*
1 2 3 
4 5 6
7 8 9

it should be like 

1 2 3
6 5 4
7 8 9

traversal be like mirrored S 

*/





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

    cout << "\nYour original array: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;


                                    // Method 1 of first wave : 

    // for (int k = 0; k < n; k++) {
    //     int i = 0;
    //     int j = n - 1;
    //     if(k%2 != 0){
    //         while (i < j) { 
    //             int temp = arr[k][i];
    //             arr[k][i] = arr[k][j];
    //             arr[k][j] = temp;
    //             i++;
    //             j--;
    //         }
            
    //     }
    // }

    // cout << "waved form array : " << endl;
    // for (int i = 0; i < m;i++){
    //     for(int j = 0; j < n;j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }


                        // Method 2:
    cout << " Wave first : " << endl;
    for (int i = 0; i < m;i++){
        if (i % 2 == 0){
            for (int j = 0; j < n;j++){
                cout << arr[i][j] << " ";
            }
        }
        else{
            for (int j = n - 1; j >= 0; j--){
                cout << arr[i][j] << " ";
            }
        }
        cout << endl;
    }

    cout << endl;
    cout << "wave second : "<<endl;
    for (int i = m-1; i >= 0;i--){
        if (i % 2 == 0){
            for (int j = 0; j < n;j++){
                cout << arr[i][j] << " ";
            }
        }
        else{
            for (int j = n - 1; j >= 0; j--){
                cout << arr[i][j] << " ";
            }
        }
        cout << endl;
    }


    cout << endl;
    cout << "wave third : "<<endl;
    for (int j = 0; j < n;j++)
    {
        if (j % 2 == 0){
            for (int i = 0; i < n;i++){
                cout << arr[i][j] << " ";
            }
        }
        else{
            for (int i = n - 1; i >= 0; i--){
                cout << arr[i][j] << " ";
            }
        }
        cout << endl;
    }

        return 0;
}
