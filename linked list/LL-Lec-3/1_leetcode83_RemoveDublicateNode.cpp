#include <iostream>
using namespace std;

// Definition of singly-linked list node
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;

        while (temp != NULL && temp->next != NULL) {
            if (temp->val == temp->next->val) {
                ListNode* duplicate = temp->next;
                temp->next = temp->next->next;
                delete duplicate;
            } else {
                temp = temp->next;
            }
        }

        return head;
    }
};

// Utility function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    if (size == 0) return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;

    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return head;
}

// Utility function to display the linked list
void display(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    int arr[] = {10, 10, 10, 20, 20, 30, 40, 40, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    ListNode* head = createList(arr, size);

    cout << "Original List: ";
    display(head);

    Solution sol;
    head = sol.deleteDuplicates(head);

    cout << "After Removing Duplicates: ";
    display(head);

    return 0;
}
