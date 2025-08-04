#include<iostream>
#include<stack>
#include<string>
using namespace std;



string solve(string val1, string val2, char ch){
    return  ch +val1+ val2;
}

int main(){
    string s = "79+4*8/3-"; 
    stack<string> val;

    for (int i = 0; i < s.length(); i++){
       if(s[i] >= 48 && s[i] <= 57){
           val.push(to_string(s[i] - 48));
       }

       else{ // * - + / no brackets 
            // kaam
            string val2 = val.top();
            val.pop();

            string val1 = val.top();
            val.pop();

            string ans = solve(val1, val2, s[i]);  // at that time s[i] is character
            val.push(ans);
       }
    }

    cout << "the ans is : " << val.top();
}