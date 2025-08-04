#include<iostream>
#include<stack>
using namespace std;

// Print stack without modifying it
void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
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

void reverse(stack<int> &st){
    // base case 
    if(st.size() == 1)
        return;
    int x = st.top();// storing the top
    st.pop();

    reverse(st);

    pushAtBottom_Rec(st, x);
}

int main() {
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    cout << "initial list : ";
    printStack(st);
    cout << endl;

    cout << "after reverse: ";
    reverse(st);
    printStack(st);

    return 0;
}
