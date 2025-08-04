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

// Push an element at bottom using iteration
void pushAtBottom(stack<int>& st, int val) {
    stack<int> temp;

    // Move all elements to temp
    while (!st.empty()) {
        temp.push(st.top());
        st.pop();
    }

    // Push new value at bottom
    st.push(val);

    // Restore all elements
    while (!temp.empty()) {
        st.push(temp.top());
        temp.pop();
    }
}

void pushAtIndx(stack<int>& st, int val, int idx) {
    stack<int> temp;
    idx = st.size() - idx;
    // Move all elements to temp
    while (st.size() > idx) {
        temp.push(st.top());
        st.pop();
    }


    st.push(val);

    // Restore all elements
    while (temp.size() > 0) {
        st.push(temp.top());
        temp.pop();
    }
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
    printStack(st);

    pushAtBottom(st, 70);
    pushAtBottom(st, 80);

    cout << "After pushing 70 at bottom: ";
    printStack(st);

    pushAtIndx(st, 100, 2);

    cout << "Afeter pusing at index 2: ";
    printStack(st);

    return 0;
}
