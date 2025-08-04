#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for (char ch : s) {
        // Push opening brackets
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } 
        else {
            // If stack is empty or mismatch happens
            if (st.empty()) return false;

            char top = st.top();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
            st.pop(); // Matched pair
        }
    }

    // All brackets should be matched
    return st.empty();
}

int main() {
    string s;
    cout << "Enter bracket string: ";
    cin >> s;

    if (isValid(s))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";

    return 0;
}
