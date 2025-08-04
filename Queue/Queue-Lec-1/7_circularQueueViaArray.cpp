#include <iostream>
using namespace std;

class CircularQueue {
private:
    int frontIndex;   // Points to the front element
    int rearIndex;    // Points to the position where the next element will be inserted
    int size;         // Actual capacity of the queue
    int* arr;         // Dynamically allocated array
    int count;        // Number of current elements

public:
    // Constructor
    CircularQueue(int capacity) {
        size = capacity;
        arr = new int[size];
        frontIndex = 0;
        rearIndex = 0;
        count = 0;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return count == 0;
    }

    // Check if the queue is full
    bool isFull() {
        return count == size;
    }

    // Enqueue operation (inserts at rearIndex and wraps around)
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << value << endl;
            return;
        }

        arr[rearIndex] = value;
        rearIndex = (rearIndex + 1) % size;  // Wrap around
        count++;
    }

    // Dequeue operation (removes from frontIndex and wraps around)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        frontIndex = (frontIndex + 1) % size;  // Wrap around
        count--;
    }

    // Get the front element
    int front() {
        if (isEmpty()) {
            cout << "Queue is empty. No front element." << endl;
            return -1;
        }
        return arr[frontIndex];
    }

    // Display queue elements in correct circular order
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements: ";
        for (int i = 0; i < count; i++) {
            int idx = (frontIndex + i) % size;
            cout << arr[idx] << " ";
        }
        cout << endl;
    }

    // Destructor to free memory
    ~CircularQueue() {
        delete[] arr;
    }
};

int main() {
    CircularQueue q(5);

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

    q.enqueue(60);  // Now this will work due to circular support
    q.enqueue(70);  // Will also work
    q.display();

    return 0;
}
