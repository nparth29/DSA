#include<iostream>
using namespace std;

int main(){
    cout << "no of rows  ";
    int n;
    cin >> n;

    /*
    // we will use extra variable to print contineous numbers
    int a = 1;
    

    for (int i = 1; i <= n;i++){
        if(i%2 != 0){
            a =1;
        }
            
        else{
            a = 0;
        }
            
        for (int j = 1; j <= i;j++){
            cout << a<< " ";
            // flipping 
            // if(a ==1)
            //     a = 0;
            // else
            //     a = 0;
            a = 1 - a;
        }
        cout << endl;
    }
    */
    for (int i = 1; i <= n;i++){
   
        for (int j = 1; j <= i;j++){
           if((i+j)%2 == 0){
               cout << 1<<" ";
           }
           else
               cout << 0<<" ";
        }
        cout << endl;
    }


}

// concept : you will find one occure only that place where rows and column sum == 0;
