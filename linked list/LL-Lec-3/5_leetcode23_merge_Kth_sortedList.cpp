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
    // Method 1: Merge from end - higher time complexity ~ O(nK^2)
    ListNode* mergeKListsSlow(vector<ListNode*>& arr) {
        if (arr.size() == 0) return NULL;

        while (arr.size() > 1) {
            ListNode* a = arr[arr.size() - 1];
            arr.pop_back();
            ListNode* b = arr[arr.size() - 1];
            arr.pop_back();

            ListNode* c = merge(a, b);
            arr.push_back(c);
        }

        return arr[0];
    }

    // Method 2: Merge from front - still O(nK^2) but different flow
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        if (arr.size() == 0) return NULL;

        while (arr.size() > 1) {
            ListNode* a = arr[0];
            arr.erase(arr.begin());
            ListNode* b = arr[0];
            arr.erase(arr.begin());

            ListNode* c = merge(a, b);
            arr.push_back(c);
        }

        return arr[0];
    }

    // Two-way merge function (like Leetcode 21)
    ListNode* merge(ListNode* list1, ListNode* list2) {
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

        if (tempA == NULL) temp->next = tempB;
        else temp->next = tempA;

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
    vector<vector<int>> input = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
    vector<ListNode*> lists;
    for (const auto& v : input) {
        lists.push_back(createList(v));
    }

    Solution sol;

    // Call Method 1
    vector<ListNode*> copy1 = lists;
    cout << "Merged list using Method 1 (merge from end):\n";
    ListNode* merged1 = sol.mergeKListsSlow(copy1);
    printList(merged1);

    // Call Method 2
    vector<ListNode*> copy2 = lists;
    cout << "Merged list using Method 2 (merge from front):\n";
    ListNode* merged2 = sol.mergeKLists(copy2);
    printList(merged2);

    return 0;
}
