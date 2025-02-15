#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector<string> arr = {"0123", "0023", "456", "00182", "940", "002901"};
    int max = stoi(arr[0]);
    string Mstr = arr[0];
    for (int i = 0; i < arr.size();i++){
        int x = stoi(arr[i]);
        if(x>max){
            max = x;
            Mstr = arr[i];
        }
    }
    cout <<"maximum number : "<< max<<endl<<"actual string : "<<Mstr;
}