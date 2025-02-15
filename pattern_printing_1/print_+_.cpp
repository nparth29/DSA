//          1 2 3 4 5

//  1           *
//  2           *
//  3       * * * * *
//  4           * 
//  5           * 
 // number of rows and column myst be odd 
 //  concept :
                // imagin a sæuare(odd length sides) and onli print middle row and column 
                // and to find middle side : n/2 +1
 

#include<iostream>
using namespace std;

int main(){
    cout << "no of rows and column : ";
    int n;
    cin >> n;
    int mid = n/2 + 1;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            if(i==mid || j == mid){
                cout << "*";
            }
            else
                cout << " ";
        }
        cout << endl;
    }
}