#include <iostream>
#include <vector>
#include <algorithm>

// Use the standard namespace for cout, vector, etc.
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

// Your Solution class for pre-order traversal.
class Solution {
public:
    /**
     * @brief A recursive helper function that performs the pre-order traversal.
     * The order is: Root -> Left -> Right.
     * @param root The current node in the traversal.
     * @param ans A reference to the vector to store the node values.
     */
    void preorder(TreeNode* root, vector<int>& ans) {
        // Base case: If the node is NULL, do nothing and return.
        if (root == NULL) return;

        // 1. Process the current node (Root).
        ans.push_back(root->val);
        // 2. Recursively traverse the left subtree (Left).
        preorder(root->left, ans);
        // 3. Recursively traverse the right subtree (Right).
        preorder(root->right, ans);
    }

    /**
     * @brief The main function to initiate the pre-order traversal.
     * @param root The root of the binary tree.
     * @return A vector of integers containing the pre-order traversal result.
     */
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        preorder(root, v);
        return v;
    }
};

// main function to demonstrate the solution
int main() {
    // We will build the following tree:
    //      1
    //     / \
    //    2   3
    //   / \ / \
    //  4  5 6  7
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Create an instance of the Solution class
    Solution sol;

    // Get the pre-order traversal result
    vector<int> result = sol.preorderTraversal(root);

    // Print the result
    cout << "Pre-order Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    // Expected output: 1 2 4 5 3 6 7

    return 0;
}