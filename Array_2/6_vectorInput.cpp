#include<iostream>
using namespace std;
#include<vector>
int main(){
    vector<int>v;
    int n;
    cout << "enter the value of n :";
    cin >> n;
    // input -> if the size is given at the time of intialization we can use method one.
    // method 1: just like array input 
    //      for (int i = 0; i < n;i++){
    //          cin >> v[i];
    //      }

        // method 2 :


    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    for (int i = 0; i < n;i++){
        cout << v[i] << " ";
    }
}