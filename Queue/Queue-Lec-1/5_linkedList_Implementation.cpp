#include<iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Queue {
private:
    Node* frontNode;  // Points to the front of the queue
    Node* rearNode;   // Points to the rear of the queue

public:
    // Constructor
    Queue() {
        frontNode = NULL;
        rearNode = NULL;
    }

    // Check if queue is empty
    bool isEmpty() {
        return frontNode == NULL;
    }

    // Enqueue (insert at rear)
    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (isEmpty()) {
            frontNode = rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
    }

    // Dequeue (remove from front)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow. Cannot dequeue." << endl;
            return;
        }
        Node* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;

        // If queue became empty after deletion
        if (frontNode == NULL) { // ---------------V IMP --------------
            rearNode = NULL;
        }
    }

    // Front element
    int front() {
        if (isEmpty()) {
            cout << "Queue is empty. No front element." << endl;
            return -1;
        }
        return frontNode->data;
    }

    // Display queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* temp = frontNode;
        cout << "Queue elements: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to clean up memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display(); // 10 20 30 40

    q.dequeue();
    q.dequeue();
    q.display(); // 30 40

    cout << "Front element: " << q.front() << endl; // 30

    q.enqueue(50);
    q.enqueue(60);
    q.display(); // 30 40 50 60

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue(); // last element dequeued
    q.dequeue(); // should show underflow
    q.display(); // should be empty

    return 0;
}
