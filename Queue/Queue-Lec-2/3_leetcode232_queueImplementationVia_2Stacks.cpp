#include <iostream>
#include <stack>
using namespace std;

// ===============================================
// ✅ Method 1: Push Efficient (O(1) push, O(n) pop/peek)
// ===============================================
class MyQueue_PushEfficient {
public:
    stack<int> st, helper;

    void push(int x) {
        st.push(x);  // Simple O(1) push
    }

    int pop() {
        // Reverse all elements except last
        while (st.size() > 1) {
            helper.push(st.top());
            st.pop();
        }
        int front = st.top();  // Last element = front of queue
        st.pop();

        // Restore original order
        while (!helper.empty()) {
            st.push(helper.top());
            helper.pop();
        }

        return front;
    }

    int peek() {
        while (st.size() > 1) {
            helper.push(st.top());
            st.pop();
        }
        int front = st.top();  // Peek front
        helper.push(st.top());
        st.pop();

        // Restore original order
        while (!helper.empty()) {
            st.push(helper.top());
            helper.pop();
        }

        return front;
    }

    bool empty() {
        return st.empty();
    }
};

// ===============================================
// ✅ Method 2: Pop Efficient (O(n) push, O(1) pop/peek)
// ===============================================
class MyQueue_PopEfficient {
public:
    stack<int> st, helper;

    void push(int x) {
        // Reverse entire stack to insert at bottom
        while (!st.empty()) {
            helper.push(st.top());
            st.pop();
        }

        st.push(x);  // Insert new element at bottom

        // Restore order
        while (!helper.empty()) {
            st.push(helper.top());
            helper.pop();
        }
    }

    int pop() {
        int front = st.top();
        st.pop();
        return front;
    }

    int peek() {
        return st.top();
    }

    bool empty() {
        return st.empty();
    }
};

// ===============================================
// 🔽 MAIN FUNCTION TO TEST BOTH QUEUES
// ===============================================
int main() {
    cout << "=== Queue Using Stack: Push Efficient ===" << endl;
    MyQueue_PushEfficient q1;

    q1.push(10);
    q1.push(20);
    q1.push(30);

    cout << "Front: " << q1.peek() << endl;  // 10
    cout << "Pop: " << q1.pop() << endl;    // 10
    cout << "Front after pop: " << q1.peek() << endl;  // 20
    cout << "Is empty? " << (q1.empty() ? "Yes" : "No") << endl;

    cout << "\n=== Queue Using Stack: Pop Efficient ===" << endl;
    MyQueue_PopEfficient q2;

    q2.push(100);
    q2.push(200);
    q2.push(300);

    cout << "Front: " << q2.peek() << endl;  // 100
    cout << "Pop: " << q2.pop() << endl;    // 100
    cout << "Front after pop: " << q2.peek() << endl;  // 200
    cout << "Is empty? " << (q2.empty() ? "Yes" : "No") << endl;

    return 0;
}
