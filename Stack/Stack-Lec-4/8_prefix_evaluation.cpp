#include<iostream>
#include<stack>
#include<string>
using namespace std;



int solve(int val1, int val2, char ch){  // we traversing backward so reverse all val now it is val2 operator val1
    if(ch == '+') return val2 + val1;
    else if(ch == '-') return val2 - val1;
    else if(ch == '*') return val2*val1;
    else return val2/val1;
}

int main(){
    string s = "-/*+79483";
    stack<int> val;

    for (int i = s.length() - 1; i >= 0;i--)  // we are traversing revers 
    {
        if (s[i] >= 48 && s[i] <= 57)
        {
            val.push(s[i] - 48);
        }

        else
        { // * - + / no brackets 
            // kaam
            int val2 = val.top();
            val.pop();

            int val1 = val.top();
            val.pop();

            int ans = solve(val1, val2, s[i]);  // at that time s[i] is character
            cout << "inside loop: " << ans<<endl;
            val.push(ans);
       }
    }

    cout << "the ans is : " << val.top();
}


// you can also do one thing 
// calculate val1 first then val2 afterwards 
// by doing this you dont have to reverse in solve fn by val2 op val1 
// since you reversed the val2 and val1 condition no need to change the solve : it will be val1 ch val2