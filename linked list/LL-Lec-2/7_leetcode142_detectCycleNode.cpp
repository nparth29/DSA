#include <iostream>
using namespace std;

// 🔗 Definition for singly-linked list node
class ListNode {
public:
    int val;
    ListNode *next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        bool flag = false; // initially assume no cycle
        ListNode *slow = head;
        ListNode *fast = head;

        // 🌀 Step 1: Detect if cycle exists using Floyd's algorithm
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                flag = true;
                break;
            }
        }

        // 🚫 No cycle
        if (flag == false) return NULL;

        // ✅ Step 2: Find starting node of cycle
        else {
            ListNode *temp = head;
            while (temp != slow) {
                slow = slow->next;
                temp = temp->next;
            }
            return slow;  // both meet at the start of cycle
        }
    }
};

// 🔧 Helper to create a list with a cycle
ListNode* createCyclicList() {
    ListNode* head = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;

    node4->next = node2; // cycle here (tail connects to node2)

    return head;
}

// 🚀 Driver code
int main() {
    Solution sol;
    ListNode* head = createCyclicList();

    ListNode* cycleStart = sol.detectCycle(head);

    if (cycleStart != NULL)
        cout << "Cycle detected at node with value: " << cycleStart->val << endl;
    else
        cout << "No cycle detected" << endl;

    return 0;
}
