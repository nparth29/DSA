// There is a singly-linked list head and we want to delete a node node in it.

// You are given the node to be deleted node. You will not be given access to the first node of head.

// All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.

// Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

// The value of the given node should not exist in the linked list.
// The number of nodes in the linked list should decrease by one.
// All the values before node should be in the same order.
// All the values after node should be in the same order.

#include <iostream>
using namespace std;

// 🌟 ListNode class for singly linked list (LeetCode style)
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Solution {
public:
    // 👉 Deletes the given node (LeetCode condition: node is not tail)
    void deleteNode(ListNode* target) {
        // Copy next node's value into target node
        target->val = target->next->val;

        // Link target node to skip next node
        target->next = target->next->next;

        // Note: LeetCode doesn't require freeing memory
        // because problem focuses on unlinking the node logically
    }
};

// 🌟 Utility function to display the list
void display(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // 🌟 Create linked list: 4 -> 5 -> 1 -> 9
    ListNode* head = new ListNode(4);
    ListNode* node2 = new ListNode(5);
    ListNode* node3 = new ListNode(1);
    ListNode* node4 = new ListNode(9);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;

    cout << "Initial list: ";
    display(head);

    Solution sol;

    // Delete node 5 (node2)
    sol.deleteNode(node2);
    cout << "After deleting node 5: ";
    display(head);

    // Now node2 has value 1 (since 1 was copied into node2)
    sol.deleteNode(node2);
    cout << "After deleting node 1: ";
    display(head);

    return 0;
}
