#include <iostream>
using namespace std;

// Definition for singly-linked list.
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// Function to rotate list to the right by k places
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) return head;

        // Step 1: Find length and tail
        ListNode* temp = head;
        ListNode* tail = NULL;
        int len = 0;
        while (temp != NULL) {
            len++;
            tail = temp;
            temp = temp->next;
        }

        // Step 2: Optimize rotation
        k = k % len;
        if (k == 0) return head;

        // Step 3: Find new tail at (len - k)th node
        int steps = len - k;
        temp = head;
        for (int i = 1; i < steps; i++) {
            temp = temp->next;
        }

        // Step 4: Reassign head and break the loop
        tail->next = head;     // make circular
        head = temp->next;     // new head
        temp->next = NULL;     // break circle

        return head;
    }
};

// Utility function to create a sample linked list: 10→20→30→40→50
ListNode* createList() {
    ListNode* head = new ListNode(10);
    ListNode* node2 = new ListNode(20);
    ListNode* node3 = new ListNode(30);
    ListNode* node4 = new ListNode(40);
    ListNode* node5 = new ListNode(50);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    return head;
}

// Utility function to print a linked list
void display(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Main function to test rotation
int main() {
    Solution sol;

    ListNode* head = createList();  // 10 → 20 → 30 → 40 → 50
    cout << "Original list: ";
    display(head);

    int k = 2;
    head = sol.rotateRight(head, k);

    cout << "After rotating by " << k << " steps: ";
    display(head);

    return 0;
}
