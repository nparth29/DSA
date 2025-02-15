#include<iostream>
using namespace std;
int main(){
    int x;
    x = 5>8 ? 10 : 1 != 2<5 ? 20 : 30;
    cout << "value of x : " << x;
    return 0;
}

//      1 != 2<5 ? 20 : 30;
//      in this(1 != 2<5) precedence of (<,>) is greater than (=,!=)
//          so 2<5 gives -> 1(true), and then 1!=1 gives -> 0(false)
//      0? 20:30 -> 30 is the output 
//      now: 5>8 ? 10 : 30 -> o/p = 30