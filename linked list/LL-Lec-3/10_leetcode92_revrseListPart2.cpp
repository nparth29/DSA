#include <iostream>
using namespace std;
#include<vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// ------------------- Solution Class -------------------
class Solution {
public:

    // Reverse entire linked list (Leetcode 206)
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* Next = NULL;

        while (curr != NULL) {
            Next = curr->next;      // Save next
            curr->next = prev;      // Reverse link
            prev = curr;            // Move prev
            curr = Next;            // Move curr
        }

        return prev;
    }

    // Reverse a portion of the list between positions `left` and `right`
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;

        ListNode* temp = head;
        ListNode* a = NULL; // Node before left
        ListNode* b = NULL; // Node at left
        ListNode* c = NULL; // Node at right
        ListNode* d = NULL; // Node after right

        int n = 1;

        while (temp) {
            if (n == left - 1) a = temp;
            if (n == left) b = temp;
            if (n == right) c = temp;
            if (n == right + 1) d = temp;
            temp = temp->next;
            n++;
        }

        // Break the links before and after the sublist
        if (a != NULL) a->next = NULL;
        c->next = NULL;

        // Reverse the middle part
        c = reverseList(b);

        // Reconnect the reversed part with remaining parts
        if (a != NULL) a->next = c; // Connect left part to reversed part
        b->next = d;                // Connect reversed part to right part

        if (a != NULL) return head; // If left > 1, head remains same
        else return c;              // If left == 1, new head is `c`
    }
};

// ------------------- Helper Functions -------------------

// Create linked list from vector
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return NULL;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (int i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

// Print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " → ";
        head = head->next;
    }
    cout << endl;
}

// ------------------- Main Function -------------------
int main() {
    Solution sol;

    // Test Case: Reverse between positions 3 and 6
    vector<int> vals = {10, 20, 30, 40, 50, 60, 70};
    ListNode* head = createList(vals);

    cout << "Original List: ";
    printList(head);

    int left = 3, right = 6;
    head = sol.reverseBetween(head, left, right);

    cout << "List after reversing from position " << left << " to " << right << ": ";
    printList(head);

    return 0;
}
