#include<iostream>
#include<stack>
using namespace std;

// Print stack without modifying it
void printStack_Rec(stack<int> &s) {
    // base case 
    if(s.size() == 0)
        return;
    int x = s.top();
    cout << x << " ";
    s.pop();
    printStack_Rec(s);
    s.push(x);
}

void printStack_RecReverse(stack<int> &s){
        // base case 
    if(s.size() == 0)
        return;
    int x = s.top();
    s.pop();
    printStack_RecReverse(s);
    cout << x << " ";
    s.push(x);
}

void pushAtBottom_Rec(stack<int>&s,int val){
    // base case 
    if(s.size() == 0){
        s.push(val);
        return;
    }
        
    int x = s.top();
    s.pop();
    pushAtBottom_Rec(s,val);
    s.push(x);
}


int main() {
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    cout << "Original stack: ";
    cout << "Display via recursion : ";
    printStack_Rec(st);
    cout << endl;
    cout << "Reverse Display via recursion: ";
    printStack_RecReverse(st);

    cout << endl;
    pushAtBottom_Rec(st, 5);
    cout << "Inserting 5 at bottom : ";
    printStack_Rec(st);

    return 0;
}
