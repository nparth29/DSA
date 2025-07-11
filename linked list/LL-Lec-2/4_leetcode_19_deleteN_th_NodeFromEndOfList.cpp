#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// 👉 Method 1: Length-based two-pass method (your logic)
ListNode* removeNthFromEndMethod1(ListNode* head, int n) {
    int len = 0;
    ListNode* temp = head;

    // Step 1: calculate length
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }

    // Step 2: Special case — delete head
    if (n == len) {
        ListNode* toDelete = head;
        head = head->next;
        delete toDelete;
        // return head;
    }

    // Step 3: reach (len - n - 1)th node (node before target)
//     🧠 Concept:
// If len = 7 and n = 3
// Then you want to delete the 5th node from the start (because 7 - 3 + 1 = 5)
// But since you want the node before that, you stop at 4th node, i.e., (len - n).
    temp = head;
    int idx = (len - n);
    for (int i = 1; i < idx; i++) {  // your style: start i=1, stop before idx
        temp = temp->next;
    }

    // Step 4: delete target
    ListNode* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;

    return head;
}

// 👉 Method 2: Fast-slow pointer method (your logic)
ListNode* removeNthFromEndMethod2(ListNode* head, int n) {
    ListNode* slow = head;
    ListNode* fast = head;

    // Move fast n+1 steps ahead
    for (int i = 1; i <= n + 1; i++) {
        if (fast == NULL) {       // ----> if we have to delete the head ( see notes)
            // deleting head case
            ListNode* toDelete = head;
            head = head->next;
            delete toDelete;
            return head;
        }
        fast = fast->next;
    }

    // Move both fast and slow
    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    // Delete target node
    ListNode* toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;

    return head;
}

// 👉 Display function
void display(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "-> NULL" << endl;
}

// 👉 Helper to create fresh list
ListNode* createList() {
    ListNode* head = new ListNode(10);
    ListNode* node2 = new ListNode(20);
    ListNode* node3 = new ListNode(30);
    ListNode* node4 = new ListNode(40);
    ListNode* node5 = new ListNode(50);
    ListNode* node6 = new ListNode(60);
    ListNode* node7 = new ListNode(70);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;

    return head;
}

int main() {
    // Test Method 1
    cout << "Initial list (Method 1): ";
    ListNode* head1 = createList();
    display(head1);

    head1 = removeNthFromEndMethod1(head1, 3);
    cout << "After removing 3rd from end (Method 1): ";
    display(head1);

    // Test Method 2
    cout << "\nInitial list (Method 2): ";
    ListNode* head2 = createList();
    display(head2);

    head2 = removeNthFromEndMethod2(head2, 3);
    cout << "After removing 3rd from end (Method 2): ";
    display(head2);

    return 0;
}
