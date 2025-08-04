#include <iostream>
#include <algorithm> 

using namespace std;

// Definition for a binary tree node.
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) {
        this->val = val;
        this->left = NULL; 
        this->right = NULL; 
    }
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base Case 1: If both nodes are NULL, they are the same.
        if (p == NULL && q == NULL) {
            return true;
        }

        // Why we use '||' here:
        // Because of the check above, we already know p and q are NOT both NULL.
        // So, if either one of them IS NULL at this point, it means one tree
        // has a node while the other doesn't, so they can't be the same.
        // This single '||' line efficiently checks both failure possibilities.
        if (p == NULL || q == NULL) {
            return false;
        }

        /*
        // The two '&&' lines below are the less efficient way of doing the same check:
        if(p == NULL && q != NULL) return false;
        if(p != NULL && q == NULL) return false;
        */

        // Base Case 2: If the node values don't match, they are not the same.
        if (p->val != q->val) {
            return false;
        }

        // Recursive Step: The trees are the same only if their left subtrees
        // AND their right subtrees are also identical.
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// main function to demonstrate the solution
int main() {
    // --- Test Case 1: Identical Trees ---
    TreeNode* p1 = new TreeNode(10);
    p1->left = new TreeNode(5);
    p1->right = new TreeNode(15);

    TreeNode* q1 = new TreeNode(10);
    q1->left = new TreeNode(5);
    q1->right = new TreeNode(15);

    // --- Test Case 2: Different Trees ---
    TreeNode* p2 = new TreeNode(10);
    p2->left = new TreeNode(5);

    TreeNode* q2 = new TreeNode(10);
    q2->right = new TreeNode(5); // Different structure

    // Create an instance of the Solution class
    Solution sol;

    // Run the checks and print the results
    // std::boolalpha makes the output "true" or "false" instead of 1 or 0
    cout << "Are tree 1 and tree 2 the same? " << boolalpha << sol.isSameTree(p1, q1) << endl; // Expected: true
    cout << "Are tree 1 and tree 3 the same? " << boolalpha << sol.isSameTree(p2, q2) << endl; // Expected: false

    return 0;
}