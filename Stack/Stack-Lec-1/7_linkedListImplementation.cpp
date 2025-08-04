#include<iostream>
using namespace std;

// Node definition
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Stack class using linked list
class Stack {
private:
    Node* top;

public:
    // Constructor
    Stack() {
        top = nullptr;
    }

    // Push operation
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    // Pop operation
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // Peek operation
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }

    // isEmpty check
    bool isEmpty() {
        return top == nullptr;
    }

    // Print Stack (Top to Bottom)
    void printStack() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

// Driver code
int main() {
    Stack st;

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
