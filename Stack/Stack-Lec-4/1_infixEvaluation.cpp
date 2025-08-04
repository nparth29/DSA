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

int solve(int val1, int val2, char ch){
    if(ch == '+') return val1 + val2;
    else if(ch == '-') return val1 - val2;
    else if(ch == '*') return val1*val2;
    else return val1/val2;
}

int main(){
    string s = "2+9*4/6-3";
    stack<int> val;
    stack<char> op;
    for (int i = 0; i < s.length(); i++){
        // check if s[i] is a digit (0-9)

        // int ascii = (int)s[i];
        // if(ascii >=48 && ascii <=57){
        // }

        // we don't need of typecast c++ automaticlly cpmpare the ascii val of char to int
        if(s[i] >= 48 && s[i] <= 57){
            val.push(s[i] - 48);
        }
        else{// not a digit * /+ -
            if(op.size() == 0){
                op.push(s[i]);
            }
            // op stack mai aane wallhe element ki priority top se jyada hai dikkat nhi
            // eg: op.top() = +  and s[i]  = * no prob 
            else if(priority(op.top()) < priority(s[i])){ 
                op.push(s[i]);
            }
            
            else{
                // work : 
                while(op.size() > 0 && priority(op.top()) >= priority(s[i])){
                    char ch = op.top();
                    op.pop();

                    int val2 = val.top();
                    val.pop();

                    int val1 = val.top();
                    val.pop();
                    int ans = solve(val1, val2, ch);
                    val.push(ans);
                }
                // ab hame vo char s[i] push krna hai op stack mai
                op.push(s[i]);
            }
        }
    }

    //  still the op stack may have values 
    // so make it empty : 
    while(op.size() > 0){
        char ch = op.top();
        op.pop();

        int val2 = val.top();
        val.pop();

        int val1 = val.top();
        val.pop();
        int ans = solve(val1, val2, ch);
        val.push(ans);
    }

    cout << val.top();
}