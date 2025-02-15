// 1 3 5 7 9 11 13 15 17 19
#include<iostream>
using namespace std;
int main(){
    int a = 1;
    int n;
    cout << "enter number of terms : ";
    cin >> n;
    for (int i = 1; i <= n;i++){
        cout << a << " ";
        a += 2;
    }
}