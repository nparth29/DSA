#include <iostream>
using namespace std;

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

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;
    int size;

    DoublyLinkedList() {
        head = tail = NULL;
        size = 0;
    }

    void insertAtHead(int val) {
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

    void insertAtTail(int val) {
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

    void insertAtIdx(int idx, int val) {
        if (idx < 0 || idx > size) {
            cout << "Invalid index" << endl;
            return;
        }

        if (idx == 0) {
            insertAtHead(val);
        } else if (idx == size) {
            insertAtTail(val);
        } else {
            Node* temp = head;
            for (int i = 0; i < idx - 1; i++) {
                temp = temp->next;
            }
            Node* newnode = new Node(val);
            newnode->next = temp->next;
            newnode->prev = temp;
            temp->next->prev = newnode;
            temp->next = newnode;
            size++;
        }
    }

    int getIdx(int idx) {
        if (idx < 0 || idx >= size) {
            cout << "Invalid index" << endl;
            return -1;
        }

        Node* temp = head;
        for (int i = 0; i < idx; i++) {
            temp = temp->next;
        }
        return temp->val;
    }

    void deleteAtHead() {
        if (!head) {
            cout << "List is empty" << endl;
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

    void deleteAtTail() {
        if (!tail) {
            cout << "List is empty" << endl;
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

    void deleteAtIdx(int idx) {
        if (idx < 0 || idx >= size) {
            cout << "Invalid index" << endl;
            return;
        }

        if (idx == 0) {
            deleteAtHead();
        } else if (idx == size - 1) {
            deleteAtTail();
        } else {
            Node* temp = head;
            for (int i = 0; i < idx; i++) {
                temp = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            size--;
        }
    }

    void reverse() {
        if (!head || !head->next) return;

        Node* curr = head;
        Node* temp = NULL;

        while (curr != NULL) {
            // swap next and prev for each node
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;

            curr = curr->prev;  // move to next (which is prev now)
        }

        // after reverse, swap head and tail
        temp = head;
        head = tail;
        tail = temp;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

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
    DoublyLinkedList dll;

    dll.insertAtTail(10);
    dll.insertAtTail(20);
    dll.insertAtTail(30);
    dll.insertAtHead(5);
    dll.insertAtIdx(2, 15);
    dll.display(); // 5 10 15 20 30

    dll.reverse();
    dll.display(); // 30 20 15 10 5

    dll.displayReverse(); // 5 10 15 20 30

    dll.deleteAtHead();
    dll.deleteAtTail();
    dll.deleteAtIdx(1);
    dll.display(); // 20

    return 0;
}
