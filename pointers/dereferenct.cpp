#include<iostream>
using namespace std;
int main(){
    int x = 10;
    int *p = &x;
    cout << *p<<endl;
    // *p mean p ke andar jo address hai us address pe jao and vha ki value print kro
    cout << x<<endl;
    *p = 89;
    cout << x;
}