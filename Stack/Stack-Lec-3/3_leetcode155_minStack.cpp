#include <iostream>
#include <stack>
#include <climits>
using namespace std;

// Method 1: Two-stack MinStack
class MinStackTwoStack {
public:
    stack<int> st;
    stack<int> helper;

    MinStackTwoStack() {}

    void push(int val) {
        st.push(val);
        if (helper.size() == 0 || val < helper.top())
            helper.push(val);
        else
            helper.push(helper.top());
    }

    void pop() {
        st.pop();
        helper.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return helper.top();
    }
};

// Method 2: One-stack with encoded minimum tracking
class MinStackOneStack {
public:
    stack<long long> st;
    long long min;

    MinStackOneStack() {
        min = LLONG_MAX;
    }

    void push(int val) {
        long long x = (long long)val;
        if (st.size() == 0) {
            min = x;
            st.push(x);
        } else if (x >= min) {
            st.push(x);
        } else {
            st.push(2 * x - min);  // push encoded dummy
            min = x;
        }
    }

    void pop() {
        if (st.top() < min) {
            long long old_min = 2 * min - st.top();
            min = old_min;
        }
        st.pop();
    }

    int top() {
        if (st.top() < min) return (int)min;
        return (int)st.top();
    }

    int getMin() {
        return (int)min;
    }
};

int main() {
    cout << "--- Using Two Stack Method ---" << endl;
    MinStackTwoStack ms1;
    ms1.push(5);
    ms1.push(3);
    ms1.push(7);
    ms1.push(2);
    cout << "Top: " << ms1.top() << endl;
    cout << "Min: " << ms1.getMin() << endl;
    ms1.pop();
    cout << "Top after pop: " << ms1.top() << endl;
    cout << "Min after pop: " << ms1.getMin() << endl;

    cout << "\n--- Using One Stack Encoded Method ---" << endl;
    MinStackOneStack ms2;
    ms2.push(5);
    ms2.push(3);
    ms2.push(7);
    ms2.push(2);
    cout << "Top: " << ms2.top() << endl;
    cout << "Min: " << ms2.getMin() << endl;
    ms2.pop();
    cout << "Top after pop: " << ms2.top() << endl;
    cout << "Min after pop: " << ms2.getMin() << endl;

    return 0;
}
