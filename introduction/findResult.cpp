#include<iostream>
using namespace std;
int main(){
    int num1;
    int p = 5, q = 10;
    p +=q-= p;
    cout << p << " " << q << endl;
    return 0;
}

// the given expression evaluated from right to left and then assign to p
//  q = q-p -> q = 5
//  p = p+q -> 