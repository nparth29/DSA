#include<iostream>
#include<stack>
#include<string>
using namespace std;

int priority(char ch){
    if(ch == '/' || ch == '*')
        return 2;
    else
        return 1; // for + and -
}

string solve(string val1, string val2, char ch){
    // return ch + val1 + val2;  // prefix : operator
    string s = "";
    s.push_back(ch);
    s += val1;
    s += val2;
    return s;
}

int main(){
    string s = "(7+9)*4/8-3";
    stack<string> val;     
    stack<char> op;
    for (int i = 0; i < s.length(); i++){

        if(s[i] >= 48 && s[i] <= 57){
            val.push(to_string(s[i] - 48));  // for convering value into string 
        }
        else{// not a digit * /+ -
            if(op.size() == 0){
                op.push(s[i]);
            }
            else if(s[i] == '(') op.push(s[i]);

            else if(op.top() == '(') op.push(s[i]);

            
            
            else if(s[i] == ')'){
                while(op.size() > 0 && op.top() != '('){
                    char ch = op.top();
                    op.pop();

                    string val2 = val.top();
                    val.pop();

                    string val1 = val.top();
                    val.pop();
                    string ans = solve(val1, val2, ch);
                    val.push(ans);
                }
                op.pop(); // this will pop (
            }
            else if(priority(op.top()) < priority(s[i])){ 
                op.push(s[i]);
            }

            else{
                // work : 
                while(op.size() > 0 && priority(op.top()) >= priority(s[i])){
                    char ch = op.top();
                    op.pop();

                    string val2 = val.top();
                    val.pop();

                    string val1 = val.top();
                    val.pop();
                    string ans = solve(val1, val2, ch);
                    cout <<"inner loop: "<< ans << endl;
                    val.push(ans);
                }
                
                op.push(s[i]);
            }
        }
    }

    //  still the op stack may have values 
    // so make it empty : 
    while(op.size() > 0){
        char ch = op.top();
        op.pop();

        string val2 = val.top();
        val.pop();

        string val1 = val.top();
        val.pop();
        string ans = solve(val1, val2, ch);
        cout <<"this is outer loop "<< ans << endl;
        
        val.push(ans);
    }

    cout <<"the prefix will be : "<< val.top();
}