       
       //       0  1  2  3 4  5  6  
        // 0    1
        // 1    1  1
        // 2    1  2  1                                                               
        // 3    1  3  3  1
        // 4    1  4  6  4  1
        // 5    1  5  10  10  5  1

// let we took a number form row 4 and column 2 ie.. 6  then it is 4C2

int fact(int x){
    int f = 1;
    for (int i = 2; i <= x;i++){
        f *= i;
       
    }
     return f;
}

int combination(int n, int r){
    int nCr = fact(n) / (fact(r) * fact(n-r));
    return nCr;
}

#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "enter the value of n : ";
    cin >> n;
    for (int i = 0; i <=n;i++){
        for (int j = 0; j <=i;j++){
            cout << combination(i, j)<<" ";
        }
        cout << endl;
    }
}