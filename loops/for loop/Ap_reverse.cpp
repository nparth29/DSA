// display this AP : 100, 97, 94, ....... upto all terms which are positive.....

#include<iostream>
using namespace std;
int main(){
    int a = 100;
    for (; a > 0;){     // imp
        cout << a << " ";
        a -= 3;
    }
}
  
/* or 

int main(){
    for (int i = 100; i >= 0;i-=3){
        // if(i>=0){
        //     cout << i<<" ";
        // }
        cout << i<<" ";
    }
}




*/