#include <iostream>
using namespace std;
#include<vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// -----------------------------
// Iterative method
ListNode* reverseListIterative(ListNode* head) {
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* Next = NULL;

    while (curr != NULL) {
        Next = curr->next;      // Store next node
        curr->next = prev;      // Reverse current node’s pointer
        prev = curr;            // Move prev to current
        curr = Next;            // Move curr to next
    }

    // prev becomes the new head of the reversed list
    return prev;
}

// -----------------------------
// Recursive method
ListNode* reverseListRecursive(ListNode* head) {
    // Base case: empty list or single node
    if (head == NULL || head->next == NULL) return head;

    // Recurse to the end of the list
    ListNode* newHead = reverseListRecursive(head->next);

    // Reverse the link
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

// -----------------------------
// Utility function to print a linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// -----------------------------
// Utility to create a list from array
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return NULL;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (int i = 1; i < vals.size(); i++) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

// -----------------------------
// Main function
int main() {
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = createList(values);

    cout << "Original List: ";
    printList(head);

    // ---------------- Iterative Reverse ----------------
    ListNode* reversedIterative = reverseListIterative(head);
    cout << "Reversed (Iterative): ";
    printList(reversedIterative);

    // Since the list is already reversed, reverse it again using recursive
    ListNode* reversedRecursive = reverseListRecursive(reversedIterative);
    cout << "Reversed Again (Recursive): ";
    printList(reversedRecursive);

    return 0;
}
