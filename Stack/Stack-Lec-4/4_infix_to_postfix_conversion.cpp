#include<iostream>
#include<stack>
#include<string>
using namespace std;

// Returns priority of operators
int priority(char ch) {
    if(ch == '/' || ch == '*')
        return 2;
    else
        return 1; // for '+' and '-'
}

// Builds postfix expression from two operands and an operator
string solve(string val1, string val2, char ch) {
    return val1 + val2 + ch;  // postfix: operand1 operand2 operator
}

int main() {
    string s = "(7+9)*4/8-3";
    stack<string> val;   // Stack to hold operand strings
    stack<char> op;      // Stack to hold operators

    for (int i = 0; i < s.length(); i++) {
        char curr = s[i];

        // If digit, push to val stack
        if(curr >= '0' && curr <= '9') {
            val.push(to_string(curr - '0'));
        }
        else {
            if(op.size() == 0 || curr == '(') {
                op.push(curr);
            }
            else if(curr == ')') {
                // Evaluate until matching '('
                while(op.size() > 0 && op.top() != '(') {
                    char ch = op.top(); op.pop();

                    string val2 = val.top(); val.pop();
                    string val1 = val.top(); val.pop();

                    string ans = solve(val1, val2, ch);
                    val.push(ans);
                }
                op.pop(); // Pop the '('
            }
            else if(op.top() == '(') {
                op.push(curr);
            }
            else if(priority(op.top()) < priority(curr)) {
                op.push(curr);
            }
            else {
                // While top of stack has higher or equal precedence
                while(op.size() > 0 && priority(op.top()) >= priority(curr)) {
                    char ch = op.top(); op.pop();

                    string val2 = val.top(); val.pop();
                    string val1 = val.top(); val.pop();

                    string ans = solve(val1, val2, ch);
                    val.push(ans);
                }
                op.push(curr);
            }
        }
    }

    // Final cleanup: process remaining operators
    while(op.size() > 0) {
        char ch = op.top(); op.pop();

        string val2 = val.top(); val.pop();
        string val1 = val.top(); val.pop();

        string ans = solve(val1, val2, ch);
        val.push(ans);
    }

    cout << "Postfix expression: " << val.top() << endl;
    return 0;
}
