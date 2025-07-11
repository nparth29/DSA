#include <iostream>
using namespace std;

// ✅ ListNode class definition
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// ✅ Solution class implementing Floyd’s Cycle Detection
class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // 🌀 Move slow by 1 step, fast by 2 steps
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            // If both pointers meet, there is a cycle
            if (slow == fast) return true;
        }

        // If fast reaches end, there is no cycle
        return false;
    }
};

// ✅ Utility to create a sample linked list
ListNode* createListWithCycle(bool makeCycle = false) {
    ListNode* head = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;

    if (makeCycle) {
        node4->next = node2;  // 🔁 Cycle here
    }

    return head;
}

// 🚀 Driver code
int main() {
    // Set to true to create a cycle, false for no cycle
    ListNode* head = createListWithCycle(true);

    Solution sol;
    if (sol.hasCycle(head)) {
        cout << "✅ Cycle detected in the linked list." << endl;
    } else {
        cout << "❌ No cycle detected in the linked list." << endl;
    }

    return 0;
}
