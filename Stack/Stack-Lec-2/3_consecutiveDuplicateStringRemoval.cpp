#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

string removeDuplicate(string &s){
    stack<char> st;
    st.push(s[0]); // now we can start loop from i +1 and compare them with top
    for (int i = 1; i < s.length();i++){
        // if(st.size() == 0)
        //     st.push(s[i]);
        if(s[i] != st.top()) st.push(s[i]);
    }
    s = "";
    while (st.size() >0)
    {
        s += st.top();
        st.pop();
    }
    
    reverse(s.begin(), s.end());
    return s;
}

int main(){
    string s = "aaabbbcddaabffg"; //abce
    cout << s<<endl;
    string op = removeDuplicate(s);
    cout<< op;
}