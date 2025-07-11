#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // Method 1: Create new nodes for merged list
    ListNode* mergeTwoListsNewNodes(ListNode* list1, ListNode* list2) {
        ListNode* tempA = list1;
        ListNode* tempB = list2;
        ListNode* c = new ListNode(-1);
        ListNode* tempC = c;

        while (tempA != NULL && tempB != NULL) {
            if (tempA->val <= tempB->val) {
                ListNode* t = new ListNode(tempA->val);
                tempC->next = t;
                tempC = t;
                tempA = tempA->next;
            } else {
                ListNode* t = new ListNode(tempB->val);
                tempC->next = t;
                tempC = t;
                tempB = tempB->next;
            }
        }

        if (tempA == NULL) {
            tempC->next = tempB;
        } else {
            tempC->next = tempA;
        }
        return c->next;
    }

    // Method 2: Use existing nodes for merged list
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* tempA = list1;
        ListNode* tempB = list2;
        ListNode* c = new ListNode(-1);
        ListNode* temp = c;

        while (tempA != NULL && tempB != NULL) {
            if (tempA->val <= tempB->val) {
                temp->next = tempA;
                temp = tempA;
                tempA = tempA->next;
            } else {
                temp->next = tempB;
                temp = tempB;
                tempB = tempB->next;
            }
        }

        if (tempA == NULL) {
            temp->next = tempB;
        } else {
            temp->next = tempA;
        }
        return c->next;
    }
};

// Utility to create a linked list from vector
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return NULL;
    ListNode* head = new ListNode(vals[0]);
    ListNode* temp = head;
    for (int i = 1; i < vals.size(); ++i) {
        temp->next = new ListNode(vals[i]);
        temp = temp->next;
    }
    return head;
}

// Utility to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << (head->next ? " -> " : "\n");
        head = head->next;
    }
}

int main() {
    vector<int> v1 = {1, 3, 5};
    vector<int> v2 = {2, 4, 6};

    ListNode* l1 = createList(v1);
    ListNode* l2 = createList(v2);

    Solution sol;

    cout << "Merged list using Method 1 (New Nodes):\n";
    ListNode* merged1 = sol.mergeTwoListsNewNodes(createList(v1), createList(v2));
    printList(merged1);

    cout << "Merged list using Method 2 (Existing Nodes):\n";
    ListNode* merged2 = sol.mergeTwoLists(l1, l2);
    printList(merged2);

    return 0;
}
