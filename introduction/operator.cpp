#include<iostream>
using namespace std;
int main(){
    // relational operator
        // == comparison -> answer will in 0 or 1 
        // != not equal to
        // > < inequality
    
    int x = 3;
    cout << (x = 5)<<endl<<endl;

    // assignment operator
    //  =, +=, -=, /=, %=
    cout << "predict the output \n";
    bool p = false;
    bool q = false;
    bool r = true;
    cout << (p == q == r);  // left to right  p==q-> true and true ==r(true)-> true(1)
}