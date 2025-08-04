#include<iostream>
using namespace std;

class Stack {
private:
    int* arr;       // dynamic array
    int top;        // points to top element
    int capacity;   // max size of stack

public:
    // Constructor
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    // Push operation
    void push(int val) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = val;
    }

    // Pop operation
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        top--;
    }

    // Peek top element
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1; // sentinel value
        }
        return arr[top];
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if stack is full
    bool isFull() {
        return top == capacity - 1;
    }

    // Print stack (top to bottom)
    void printStack() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }
};

int main() {
    Stack st(10); // Stack with capacity 10

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    cout << "Current Stack: ";
    st.printStack(); // Should print 50 40 30 20 10

    cout << "Top element: " << st.peek() << endl;

    st.pop();
    st.pop();

    cout << "After popping 2 elements: ";
    st.printStack(); // Should print 30 20 10

    return 0;
}
