#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Solution {
public:
    // Display the queue without modifying the order
    void display(queue<int>& q) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            cout << q.front() << " ";
            int x = q.front();
            q.pop();
            q.push(x);
        }
        cout << endl;
    }

    // Reorder function to rearrange queue in specific pattern
    void reorder(queue<int>& q){
        int n = q.size() / 2;
        stack<int> st;

        // Step 1: Push first half into stack, then back to queue to reverse the first half
        for (int i = 0; i < n; i++) {
            st.push(q.front());
            q.pop();
        }
        for (int i = 0; i < n; i++) {
            q.push(st.top());
            st.pop();
        }

        // Step 2: Push first half of the current queue into stack (originally reversed half)
        for (int i = 0; i < n; i++) {
            st.push(q.front());
            q.pop();
        }

        // Step 3: Interleave stack and queue elements
        while (!st.empty()) {
            q.push(st.top());
            st.pop();
            q.push(q.front());
            q.pop();
        }

        // Step 4: Reverse the entire queue using stack to fix final ordering
        while (!q.empty()) {
            st.push(q.front());
            q.pop();
        }
        while (!st.empty()) {
            q.push(st.top());
            st.pop();
        }
    }
};

int main() {
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);

    Solution sol;

    cout << "The initial queue is : ";
    sol.display(q);

    sol.reorder(q);

    cout << "The reordered queue is : ";
    sol.display(q);

    return 0;
}
