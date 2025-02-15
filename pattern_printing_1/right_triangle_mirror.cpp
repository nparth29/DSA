       
//         1  2  3  4  5  6
//  1      @  @  @  @  @  *
//  2      @  @  @  @  *  *
//  3      @  @  @  *  *  *
//  4      @  @  *  *  *  *
//  5      @  *  *  *  *  *
// 6       *  *  *  *  *  *

// @ ek row column kam hai to revrse triangle mai n+1-i ki jagha n-i lagega

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
            cout << endl;
            
    }
    
}

// lower right triangle and right triangle ko andd kiya hai


// method 2 most imp 
    // note if we have to print only diagonal  we give the condition if(i+j== n+1)
    // but hame uske aage ka vhi chaiyea to the condition will be  if(i+j >=n+1)
    // for(int i = 1; i<=n;i++){
    //     for (int j = 1; j <= n;j++){
    //         if(i+j >=n+1)
    //             cout << "*";
    //     else{
    //         cout << " ";
    //     }
    //     cout << endl;
    //     }

    // }