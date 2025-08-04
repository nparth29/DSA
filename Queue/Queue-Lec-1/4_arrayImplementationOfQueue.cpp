#include<iostream>
using namespace std;

class Queue {
private:
    int frontIndex;     // Points to the front element
    int rearIndex;      // Points to the position where the next element will be inserted
    int size;           // Maximum capacity of the queue
    int* arr;           // Dynamically allocated array for queue storage

public:
    // Constructor
    Queue(int capacity) {
        size = capacity;
        arr = new int[size];
        frontIndex = 0;
        rearIndex = 0;
    }

    // Check if queue is empty
    bool isEmpty() {
        return frontIndex == rearIndex;
    }

    // Check if queue is full
    bool isFull() {
        return rearIndex == size;
    }

    // Enqueue operation (add element at the rear)
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << value << endl;
            return;
        }
        arr[rearIndex] = value;
        rearIndex++;
    }

    // Dequeue operation (remove element from the front)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        frontIndex++;
    }

    // Get the front element
    int front() {
        if (isEmpty()) {
            cout << "Queue is empty. No front element." << endl;
            return -1;
        }
        return arr[frontIndex];
    }

    // Display the queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = frontIndex; i < rearIndex; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Destructor to release memory
    ~Queue() {
        delete[] arr;
    }
};


int main() {
    Queue q(5);  // Create a queue of size 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();

    q.dequeue();
    q.dequeue();
    q.display();

    cout << "Front element: " << q.front() << endl;

    q.enqueue(60);  // Will not work due to no circular support
    q.display();

    return 0;
}
