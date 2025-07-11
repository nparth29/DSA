// ----------------------------------------------------
// Leetcode 86: Partition List — Two Linked List Buckets
// ----------------------------------------------------
// Problem: Given the head of a linked list and an integer x,
// partition the list such that all nodes less than x come before nodes >= x.
// The relative order of nodes in each partition must be preserved.

// Example Input: head = 1 → 4 → 3 → 2 → 5 → 2, x = 3
// Expected Output: 1 → 2 → 2 → 4 → 3 → 5

// ----------------------------------------------------
// Concept and Step-by-Step Algorithm
// ----------------------------------------------------

// Idea:
// We split the list into two linked lists:
// 1. One for values < x
// 2. One for values >= x
// Then we concatenate them at the end to form the final list.
//
// We use two dummy nodes `lo` and `hi` to build the two lists separately.
// This ensures we don't lose any nodes and avoid handling head null cases.

// Step-by-Step:

// 1. Initialize dummy nodes:
//    ListNode* lo = new ListNode(-1);  // Dummy for < x
//    ListNode* hi = new ListNode(-1);  // Dummy for >= x

// 2. Use two tail pointers:
//    tempLo → tail of < x list
//    tempHi → tail of >= x list

// 3. Traverse the original list:
//    For each node:
//      - If node->val < x, add it to the lo list
//      - Else, add it to the hi list

//    while(temp != NULL) {
//        if(temp->val < x) {
//            tempLo->next = temp;
//            tempLo = tempLo->next;
//        } else {
//            tempHi->next = temp;
//            tempHi = tempHi->next;
//        }
//        temp = temp->next;
//    }

// 4. Terminate both lists to avoid cycles:
//    tempHi->next = NULL;

// 5. Join the lo list with the hi list:
//    tempLo->next = hi->next;

// 6. Return the new head:
//    return lo->next;

// ----------------------------------------------------
// Dry Run (Example): head = 1 → 4 → 3 → 2 → 5 → 2, x = 3
//
// Iteration | temp->val | Action       | lo list       | hi list
// ----------|-----------|--------------|---------------|-----------------
//    1      |    1      | lo add       | 1             | -
//    2      |    4      | hi add       | 1             | 4
//    3      |    3      | hi add       | 1             | 4 → 3
//    4      |    2      | lo add       | 1 → 2         | 4 → 3
//    5      |    5      | hi add       | 1 → 2         | 4 → 3 → 5
//    6      |    2      | lo add       | 1 → 2 → 2     | 4 → 3 → 5

// After Connection:
// lo → 1 → 2 → 2 → 4 → 3 → 5

// ----------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(1) — Only pointers used (dummy nodes)
// ----------------------------------------------------



#include <iostream>
using namespace std;
#include<vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Solution class containing the partition function
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // Dummy nodes to build the two lists:
        //  - lo: stores nodes < x
        //  - hi: stores nodes >= x
        ListNode* lo = new ListNode(-1);
        ListNode* hi = new ListNode(-1);

        // Temp pointers to iterate over lo and hi lists
        ListNode* tempLo = lo;
        ListNode* tempHi = hi;

        ListNode* temp = head;

        // Traverse original list and separate nodes into two lists
        while (temp != NULL) {
            if (temp->val < x) {
                // Append to lo list
                tempLo->next = temp;
                tempLo = tempLo->next;
            } else {
                // Append to hi list
                tempHi->next = temp;
                tempHi = tempHi->next;
            }
            temp = temp->next;
        }

        // Important:
        //  - Terminate hi list properly to avoid cycle
        //  - Connect end of lo list to head of hi list
        tempHi->next = NULL;
        tempLo->next = hi->next;

        // Return head of new list
        return lo->next;
    }
};

// Helper function to print linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(vector<int> vals) {
    if (vals.empty()) return NULL;
    ListNode* head = new ListNode(vals[0]);
    ListNode* temp = head;
    for (int i = 1; i < vals.size(); i++) {
        temp->next = new ListNode(vals[i]);
        temp = temp->next;
    }
    return head;
}

int main() {
    Solution sol;

    // Test case: [1,4,3,2,5,2], x = 3
    vector<int> vals = {1, 4, 3, 2, 5, 2};
    ListNode* head = createList(vals);

    cout << "Original List: ";
    printList(head);

    int x = 3;
    ListNode* newHead = sol.partition(head, x);

    cout << "Partitioned List (x = " << x << "): ";
    printList(newHead);

    return 0;
}
