#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string s) {
        queue<int>q; 
        queue<int>r;
        queue<int>d;

        for(int i = 0; i < s.length(); i++){
            q.push(i);
            if(s[i] == 'R') r.push(i);
            else d.push(i);
        }  // all queue are set now 

        while(q.size() >1){
            if(s[q.front()] == 'X') q.pop();
            else if(s[q.front()] == 'R'){
                // check the victory 
                if(d.size() == 0) return "Radiant";
                else{ // take the rights of next D
                    // pop the element from d
                    s[d.front()] = 'X';
                    d.pop(); 

                    // push and pop from r and s
                    r.push(r.front());
                    r.pop();
                    q.push(q.front());
                    q.pop();
                }
            }

            else{ // s[q.front() == 'D]
                // check the victory 
                if(r.size() == 0) return "Dire";
                else{
                    // take the rights of next R
                    s[r.front()] = 'X';
                    r.pop();

                    // push and pop from d and q
                    d.push(d.front());
                    d.pop();
                    q.push(q.front());
                    q.pop();
                }
            }
        }
        // the loop will break if size become one 
        // this case dither d has one element or r and one of them is empty 
        if(d.size() == 0) return "Radiant";
        else return "Dire";
    }
};


int main() {
    Solution sol;
    string senate;

    cout << "Enter the senate string (e.g., RDDR): ";
    cin >> senate;

    string result = sol.predictPartyVictory(senate);
    cout << "Winning party: " << result << endl;

    return 0;
}
