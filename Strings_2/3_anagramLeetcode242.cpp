// anagram is the one of the permutation of the string 
// to check the strings are anagram sort the strings if the storted strings are same then they are anagram

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s;
    cout << "Input string 's' : ";
    cin >> s;
    string t;
    cout << "Input string 't' : ";
    cin>>t;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    if(s==t){
        cout << "'true' the strings are anagram ";
    }
    else
        cout << "'false' the strings are not anagram";
}