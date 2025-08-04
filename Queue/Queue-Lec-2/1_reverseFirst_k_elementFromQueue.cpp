#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseFirstK(queue<int>& q, int k) {
    if (q.empty() || k <= 0 || k > q.size()) return;

    stack<int> st;

    // Step 1: Push first k elements into the stack
    for (int i = 0; i < k; i++) {
        st.push(q.front());
        q.pop();
    }

    // Step 2: Enqueue back the stack elements (they are reversed)
    while (st.size() > 0) {
        q.push(st.top());
        st.pop();
    }

    // Step 3: Move the remaining elements (n-k) to the back of the queue
    int remaining = q.size() - k;
    for (int i = 0; i < remaining; i++) {
        q.push(q.front());
        q.pop();
    }
}

void display(queue<int>& q){
    int size = q.size();
    for (int i = 0; i < size;i++){
        cout<<q.front()<<" ";
        int x = q.front();
        q.pop();

        q.push(x);
    }
    cout << endl;
}

int main() {
    queue<int> q;

    // Sample input: 10 20 30 40 50 60 70
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);

    int k = 4;
    cout << "Original Queue: ";
    display(q);

    reverseFirstK(q, k);

    cout << "Queue after reversing first " << k << " elements: ";
    display(q);

    return 0;
}
