#include<iostream>
// #include<vector>
using namespace std;

void bubbleSort(string &str){
    int n = str.size();
    for (int i = 0; i < n - 1; i++){
        bool flag = true;  // assume the string is already sorted in decreasing order
         for (int j = 0; j < n - 1 - i; j++){
            if(str[j] < str[j+1]){
                swap(str[j], str[j+1]);
                flag = false; // mark that a swap occurred
            }
        }
        for (int j = 0; j < n - 1 - i; j++){
            if(str[j] < str[j+1]){  // if str[j] is smaller then str[j+1] then we swap it because we want to sort in decreasing order
                swap(str[j], str[j+1]);
                flag = false;
            }
        }
        if(flag) break;
    }
}
// sort the string in decreasing order of value associatd after removal of value smaller than x 
int main(){
    string s = "azyzxbdjkx";
    string str;
    for (int i = 0; i < s.size();i++){
        if(s[i] >= 'x'){
            str.push_back(s[i]);
        }
    }
    cout << str << endl;

    bubbleSort(str);
    cout <<"sorted string:" <<str << endl;
}