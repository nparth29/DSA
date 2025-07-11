#include <iostream>
#include <vector>
using namespace std;

// Definition of singly linked list node
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val) {
        this->val = val;
        next = NULL;
    }
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // Step 1: Count the number of nodes in the list
        int n = 0;
        ListNode* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }

        // Step 2: Compute base size of each part and the remainder
        int size = n / k;        // Every part gets at least 'size' nodes
        int rem = n % k;         // First 'rem' parts get one extra node

        // Step 3: Start splitting the list into k parts
        vector<ListNode*> ans;
        temp = head;

        while (temp) {
            // Create a dummy node to help build the current part
            ListNode* dummy = new ListNode(-1);
            ListNode* tempC = dummy;

            int s = size;
            if (rem > 0) {
                s++;  // Give this part one extra node if available
                rem--;
            }

            // Step 4: Move 's' nodes from original list into the current part
            for (int i = 0; i < s && temp; i++) {
                tempC->next = temp;
                tempC = tempC->next;
                temp = temp->next;
            }

            // Step 5: Break the link to the rest of original list
            tempC->next = NULL;

            // Step 6: Push the part into result vector
            ans.push_back(dummy->next);
        }

        // Step 7: If total nodes < k, push NULL to fill remaining parts
        while (ans.size() < k) {
            ans.push_back(NULL);
        }

        return ans;
    }
};

// Utility function to print a single linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Utility function to create linked list from vector
ListNode* createList(vector<int>& values) {
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;
    for (int val : values) {
        temp->next = new ListNode(val);
        temp = temp->next;
    }
    return dummy->next;
}

int main() {
    // Create a linked list from vector
    vector<int> vals = {1, 2, 3, 4, 5, 6, 7};
    ListNode* head = createList(vals);

    // ✅ Show the original list
    cout << "Original List: ";
    printList(head);

    int k = 3;  // Number of parts to split into

    Solution sol;
    vector<ListNode*> result = sol.splitListToParts(head, k);

    // ✅ Print the parts
    cout << "\nSplit into " << k << " parts:\n";
    for (int i = 0; i < result.size(); i++) {
        cout << "Part " << i + 1 << ": ";
        printList(result[i]);
    }

    return 0;
}
