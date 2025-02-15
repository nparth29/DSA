// Number divisible by 5 or 3 but not by 15

#include<iostream>
using namespace std;

int main(){
    int x;
    cout << "enter a numbr : ";
    cin >> x;
    if(x%3==0 || x%5==0)
    {
        if(x%15 != 0)
        {
            cout << "Give number satisfy the condition ;)";
        }
        else
        {
        cout << "Give number not satisfy the condition ;(";
        }
    }

     else
    {
        cout << "Give number not satisfy the condition ;(";
    }

    
    
}