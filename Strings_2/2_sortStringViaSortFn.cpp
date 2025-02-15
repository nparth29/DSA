#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    string s;
    cout << "Enter a string : ";
    // cin >> s;
    getline(cin, s); // space are printed first after that characters get printed
                     // it is because spaces ascii values are smaller than the alphabets
    sort(s.begin(), s.end());
    cout << s << endl;
}