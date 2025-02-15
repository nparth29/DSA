#include<iostream>
#include<cmath>
// hcf should be less than equal to the minimum of the two number 
using namespace std;

// mthod 1 )
// int HCF(int x,int y){
//     int hcf = 1;
//     for (int i = 1; i <= min(x, y);i++){
//         if(x%i==0 || y%i ==0)
//             hcf = i;
//     }
//     return hcf;
// }

int HCF(int x,int y){
    int hcf = 1;
    for (int i = min(x, y); i >= 1;i--){
        if(x%i==0 || y%i ==0)
            hcf = i;
            break;
    }
    return hcf;
}

int main(){
    int x;
    cout << "enter the first number : ";
    cin >> x;
    int y;
    cout << "enter the second number : ";
    cin >> y;
    cout << HCF(x, y);
}