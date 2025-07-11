#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

// ---------- Solution Class Starts ----------
class Solution {
public:

    // Reverse a linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head; 
        ListNode* prev = NULL; 
        ListNode* Next = NULL;

        while(curr) {
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }

    // ------------------ Method 1 -------------------------
    // O(n) time, O(n) space: Deep copy + Reverse
    bool isPalindromeMethod1(ListNode* head) {
        // Step 1: Create deep copy
        ListNode* c = new ListNode(-1);  // dummy node
        ListNode* tempC = c;
        ListNode* temp = head;

        while(temp != NULL) {
            ListNode* node = new ListNode(temp->val);  // new node with same value
            tempC->next = node;
            temp = temp->next;
            tempC = tempC->next;
        }

        c = c->next; // skip dummy node and point to actual head of copy

        // Step 2: Reverse the deep copy
        c = reverseList(c);

        // Step 3: Compare original and reversed copy
        temp = head;
        tempC = c;

        while(tempC != NULL) {
            if(temp->val != tempC->val) return false;
            temp = temp->next;
            tempC = tempC->next;
        }
        return true;
    }

    // ------------------ Method 2 -------------------------
    // O(n) time, O(1) space: Break in half + Reverse second half
    bool isPalindromeMethod2(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;

        // Step 1: Find middle using fast and slow pointers
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half of the list
        ListNode* secondHalf = reverseList(slow->next);

        // Step 3: Compare both halves
        ListNode* firstHalf = head;
        ListNode* second = secondHalf;

        while(second != NULL) {
            if(firstHalf->val != second->val) return false;
            firstHalf = firstHalf->next;
            second = second->next;
        }

        return true;
    }
};
// ---------- Solution Class Ends ----------


// ---------- Utility Function to Build and Print Linked List ----------
ListNode* buildList(initializer_list<int> values) {
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;
    for(int val : values) {
        temp->next = new ListNode(val);
        temp = temp->next;
    }
    return dummy->next;
}

void printList(ListNode* head) {
    while(head) {
        cout << head->val;
        if(head->next) cout << " → ";
        head = head->next;
    }
    cout << endl;
}

// ---------- Main Function ----------
int main() {
    // Create test list: Change values to test different cases
    ListNode* head = buildList({1, 2, 3, 2, 1});
    
    Solution sol;

    cout << "Input Linked List: ";
    printList(head);

    cout << "\nChecking with Method 1 (Deep Copy + Reverse): ";
    cout << (sol.isPalindromeMethod1(head) ? "Palindrome ✅" : "Not Palindrome ❌") << endl;

    cout << "Checking with Method 2 (In-place Reverse 2nd Half): ";
    cout << (sol.isPalindromeMethod2(head) ? "Palindrome ✅" : "Not Palindrome ❌") << endl;

    return 0;
}
