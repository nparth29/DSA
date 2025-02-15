
                //      1 2 3 4 5  
                // 1    *       *
                // 2      *   * 
                // 3        *  
                // 4      *   * 
                // 5    *       *



#include<iostream>
using namespace std;

int main(){
    cout << "no of rows and column (odd number): ";
    int n;
    cin >> n;
    
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            if(i==j || i+j == n+1){
                cout << "*";
            }
            else
                cout << " ";
        }
        cout << endl;
    }
}