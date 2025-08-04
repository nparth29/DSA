#include <iostream>
using namespace std;

// Node structure for doubly linked list
class Node {
public:
    int val;
    Node* next;
    Node* prev;

    Node(int val) {
        this->val = val;
        next = prev = NULL;
    }
};

// Deque class using doubly linked list
class Deque {
private:
    Node* head;
    Node* tail;
    int size;

public:
    Deque() {
        head = tail = NULL;
        size = 0;
    }

    // Insert element at front
    void pushFront(int val) {
        Node* newnode = new Node(val);
        if (!head) {
            head = tail = newnode;
        } else {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
        size++;
    }

    // Insert element at rear
    void pushBack(int val) {
        Node* newnode = new Node(val);
        if (!tail) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        size++;
    }

    // Remove element from front
    void popFront() {
        if (!head) {
            cout << "Deque is empty" << endl;
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = NULL;
        } else {
            Node* temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
        }
        size--;
    }

    // Remove element from rear
    void popBack() {
        if (!tail) {
            cout << "Deque is empty" << endl;
            return;
        }
        if (head == tail) {
            delete tail;
            head = tail = NULL;
        } else {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
        }
        size--;
    }

    // Get front element
    int getFront() {
        if (!head) {
            cout << "Deque is empty" << endl;
            return -1;
        }
        return head->val;
    }

    // Get rear element
    int getBack() {
        if (!tail) {
            cout << "Deque is empty" << endl;
            return -1;
        }
        return tail->val;
    }

    // Check if deque is empty
    bool isEmpty() {
        return size == 0;
    }

    // Get current size
    int getSize() {
        return size;
    }

    // Display from front to rear
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Display from rear to front
    void displayReverse() {
        Node* temp = tail;
        while (temp) {
            cout << temp->val << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    Deque dq;

    dq.pushBack(10);
    dq.pushBack(20);
    dq.pushFront(5);
    dq.pushFront(2);
    dq.display();         // 2 5 10 20

    dq.popFront();
    dq.popBack();
    dq.display();         // 5 10

    cout << "Front: " << dq.getFront() << endl; // 5
    cout << "Back: " << dq.getBack() << endl;   // 10

    dq.displayReverse();  // 10 5

    return 0;
}
