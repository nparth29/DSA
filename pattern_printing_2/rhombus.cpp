#include<iostream>
using namespace std;
int main(){
    cout << "enter number of rows: ";
    int r;
    cin >> r;
    // int c;
    // cout << "enter number of columb : ";
    // cin >> c;
    for (int i = 1; i <= r;i++){
        for (int j = 1; j<= r-i;j++){   // (n+1-i nhi lenge) coz hame " " ek row column kam chaiyew
            cout << " "<<" ";
        }

        for (int k = 1; k <= i;k++){
            cout << "*"<<" ";
        }

        for (int j = 1; j<= r-i;j++){   // (n+1-i nhi lenge) coz hame " " ek row column kam chaiyew
            cout << "*"<<" ";
            }
        
            cout << endl;
            
    }
    
}

// method 2;

// for (int i = 1; i <= r;i++){
//         for (int j = 1; j<= r-i;j++){   // (n+1-i nhi lenge) coz hame " " ek row column kam chaiyew
//             cout << " "<<" ";
//         }
        
//         for (int j = 1; j <= r; j++){
//                 cout << "* ";
//         }
//     cout << endl;    
//     }