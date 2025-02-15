#include<iostream>
using namespace std;
#include <string>
int main(){
    int x = 12345;
    string s = to_string(x);
    cout << s;
    // now 1245 will act as a string
    s.push_back('6');
    cout << endl
         << s;
    return 0;
}