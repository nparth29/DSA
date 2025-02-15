#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "enter number of rows : ";
    cin >> n;

    // *                     we can clearly say odd no ap  1 3 5 7  so 
    // ***                   j(no of stars in each rows) = 2*i -1
    // *****                                         -> this is the condition of i in second for
    // *******
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= (2 * i) - 1;j++){
            cout << "*";
        }
        cout << endl;
    }
}