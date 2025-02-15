// print : 1234
//         1234
//         1234

#include<iostream>
using namespace std;
int main(){
    cout << "enter number of rows: ";
    int r;
    cin >> r;
    int c;
    cout << "enter number of columb : ";
    cin >> c;
    for (int i = 1; i <= r;i++){
        for (int j = 1; j<= c;j++){
            cout << j;
        }
        cout << endl;
    }
}