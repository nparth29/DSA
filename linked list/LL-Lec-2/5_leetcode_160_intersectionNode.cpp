#include <iostream>
using namespace std;

// ✅ LeetCode-style ListNode definition
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// ✅ Solution class with helper + main logic
class Solution {
public:

    // 🔧 Helper function to calculate length of a linked list
    int length(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // 🚩 Main function to find intersection node
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int l1 = length(headA);
        int l2 = length(headB);

        // Move the pointer of longer list ahead
        if (l1 > l2) {
            for (int i = 1; i <= l1 - l2; i++) {
                headA = headA->next;
            }
        } else {
            for (int i = 1; i <= l2 - l1; i++) {
                headB = headB->next;
            }
        }

        // Move both pointers together
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;  // This is the intersection node or NULL if no intersection
    }
};

// ✅ Utility to display a linked list
void display(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// ✅ Helper to create two intersecting linked lists
void createIntersectingLists(ListNode*& headA, ListNode*& headB, ListNode*& intersection) {
    // List A: 1 -> 2 -> 3 \
    //                       ->  6 -> 7
    // List B:       4 -> 5 /

    // Shared part
    intersection = new ListNode(6);
    intersection->next = new ListNode(7);

    // List A
    headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = intersection;

    // List B
    headB = new ListNode(4);
    headB->next = new ListNode(5);
    headB->next->next = intersection;
}

// 🚀 Main
int main() {
    ListNode* headA = NULL;
    ListNode* headB = NULL;
    ListNode* intersection = NULL;

    createIntersectingLists(headA, headB, intersection);

    cout << "List A: ";
    display(headA);
    cout << "List B: ";
    display(headB);

    Solution sol;
    ListNode* ans = sol.getIntersectionNode(headA, headB);

    if (ans)
        cout << "✅ Intersection node value: " << ans->val << endl;
    else
        cout << "❌ No intersection found" << endl;

    return 0;
}
