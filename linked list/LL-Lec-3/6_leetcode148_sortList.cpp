#include <iostream>
using namespace std;
#include<vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 🧩 Helper: Merge Two Sorted Linked Lists (Leetcode 21 logic)
ListNode* merge(ListNode* list1, ListNode* list2) {
    ListNode* tempA = list1;
    ListNode* tempB = list2;
 
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;

    while(tempA != NULL && tempB != NULL){
        if(tempA->val <= tempB->val){
            temp->next = tempA;
            temp = tempA;
            tempA = tempA->next;
        }
        else{
            temp->next = tempB;
            temp = tempB;
            tempB = tempB->next;
        }
    }

    if(tempA == NULL){
        temp->next = tempB;
    }
    else{
        temp->next = tempA;
    }

    return dummy->next;
}

// 🔁 Recursive Merge Sort
ListNode* sortList(ListNode* head) {
    if(head == NULL  || head->next == NULL) return head; 

    // Step 1: Find middle of the list (left-middle for even-sized list)
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Break the list into two halves
    ListNode* a = head;
    ListNode* b = slow->next;
    slow->next = NULL;

    // Step 3: Recursively sort each half
    a = sortList(a);
    b = sortList(b);

    // Step 4: Merge sorted halves
    ListNode* c = merge(a, b);
    return c;
}

// Utility: Create a linked list from vector
ListNode* createList(const vector<int>& vals) {
    if(vals.empty()) return NULL;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for(size_t i = 1; i < vals.size(); ++i) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

// Utility: Print a linked list
void printList(ListNode* head) {
    while(head != NULL) {
        cout << head->val;
        if(head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// 🧪 Main Function to Test
int main() {
    vector<int> vals = {4, 2, 1, 3};
    ListNode* head = createList(vals);

    cout << "Original list: ";
    printList(head);

    head = sortList(head);

    cout << "Sorted list: ";
    printList(head);

    return 0;
}
