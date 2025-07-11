

#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// 👉 Deletes the target node from the linked list
// Returns updated head (important if head is deleted)
Node* deleteNode(Node* head, Node* target) {
    // Case: list is empty or target is NULL
    if (head == NULL || target == NULL) {
        return head;  // Nothing to do
    }

    // ✅ Case 1: Target is the head node
    if (head == target) {
        Node* temp = head;      // Save current head
        head = head->next;      // Move head to next node
        delete temp;            // Free memory of old head
        return head;            // Return new head
    }

    // ✅ Case 2: Target is not head → find (target-1) node
    Node* temp = head;
    while (temp->next != target) {
        temp = temp->next;
    }

    // Link (target-1) node to (target+1) node
    temp->next = temp->next->next;

    // Free memory of target node
    delete target;

    return head;
}

// 👉 Displays the linked list
void display(Node* head) {
    Node* temp = head;
    if (temp == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // 🌟 Create list: 10 -> 20 -> 30 -> 40 -> 50
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    cout << "Initial list: ";
    display(head);

    // Delete head (10)
    head = deleteNode(head, head);
    cout << "After deleting head (10): ";
    display(head);

    // Delete second node (20)
    head = deleteNode(head, second);
    cout << "After deleting node (20): ";
    display(head);

    // Delete third node (30)
    head = deleteNode(head, third);
    cout << "After deleting node (30): ";
    display(head);

    // Delete fourth node (40)
    head = deleteNode(head, fourth);
    cout << "After deleting node (40): ";
    display(head);

    // Delete fifth node (50)
    head = deleteNode(head, fifth);
    cout << "After deleting node (50): ";
    display(head);

    return 0;
}
