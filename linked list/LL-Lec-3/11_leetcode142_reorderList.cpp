#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// ---------------------- Solution Class ----------------------
class Solution {
public:
    // Reverse a linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head; 
        ListNode* prev = NULL; 
        ListNode* Next = NULL;

        while (curr) {
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }

    // Reorder List
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        // Step 1: Find middle node
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* secondHalf = reverseList(slow->next);
        slow->next = NULL;  // Terminate first half

        // Step 3: Merge two halves alternately
        ListNode* firstHalf = head;
        ListNode* tempC = new ListNode(-1);  // Dummy node
        ListNode* dummy = tempC;

        while (firstHalf && secondHalf) {
            tempC->next = firstHalf;
            firstHalf = firstHalf->next;
            tempC = tempC->next;

            tempC->next = secondHalf;
            secondHalf = secondHalf->next;
            tempC = tempC->next;
        }

        // If any nodes are left in firstHalf (odd-length list)
        if (firstHalf) tempC->next = firstHalf;

        // Finally, update the original head to reordered list
        head = dummy->next;
    }
};

// ---------------------- Helper Functions ----------------------

// Create linked list from vector
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        current->next = new ListNode(vals[i]);
        current = current->next;
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

// ---------------------- Main Function ----------------------
int main() {
    Solution sol;

    // Example input list
    vector<int> vals = {1, 2, 3, 4, 5};
    ListNode* head = createList(vals);

    cout << "Original List:\n";
    printList(head);

    sol.reorderList(head);

    cout << "Reordered List:\n";
    printList(head);

    return 0;
}
