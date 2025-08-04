#include<iostream>
#include<stack>

using namespace std;

bool isBalanced(string s){
    if(s.length() % 2 != 0)
        return false;

    stack<char> st;

    for (int i = 0; i < s.length(); i++){
        if(s[i] == '(') st.push(s[i]);
        
        else{
            if(st.size() == 0) return false;
            else
                st.pop();
        }
    }

    if(st.size() == 0) return true;
    else return false;
}

int main(){
    string s1 = "())())";
    string s2 = "()()()";

    cout << "s1: " << (isBalanced(s1) ? "Balanced" : "Not Balanced") << endl;
    cout << "s2: " << (isBalanced(s2) ? "Balanced" : "Not Balanced") << endl;

    return 0;
}