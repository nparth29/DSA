#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = m - 1;
        ListNode* temp = head;

        vector<vector<int>> spiralMatrix(m, vector<int>(n, -1));

        while (left <= right && top <= bottom) {
            // moving right
            for (int i = left; i <= right; i++) {
                if (temp == NULL) return spiralMatrix;
                spiralMatrix[top][i] = temp->val;
                temp = temp->next;
            }
            top++;

            // moving down
            for (int i = top; i <= bottom; i++) {
                if (temp == NULL) return spiralMatrix;
                spiralMatrix[i][right] = temp->val;
                temp = temp->next;
            }
            right--;

            // moving left
            for (int i = right; i >= left; i--) {
                if (temp == NULL) return spiralMatrix;
                spiralMatrix[bottom][i] = temp->val;
                temp = temp->next;
            }
            bottom--;

            // moving up
            for (int i = bottom; i >= top; i--) {
                if (temp == NULL) return spiralMatrix;
                spiralMatrix[i][left] = temp->val;
                temp = temp->next;
            }
            left++;
        }

        return spiralMatrix;
    }
};

// 👇 Optional: Utility function to create a linked list from vector
ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < values.size(); ++i) {
        curr->next = new ListNode(values[i]);
        curr = curr->next;
    }
    return head;
}

// 👇 Optional: Utility to print the 2D matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row)
            cout << num << " ";
        cout << endl;
    }
}

// 👇 Sample usage
int main() {
    vector<int> listValues = {3, 0, 2, 6, 8, 1, 7, 9, 4, 2, 5, 5, 0};
    ListNode* head = createLinkedList(listValues);
    int m = 3, n = 4;

    Solution sol;
    vector<vector<int>> result = sol.spiralMatrix(m, n, head);
    printMatrix(result);

    return 0;
}
