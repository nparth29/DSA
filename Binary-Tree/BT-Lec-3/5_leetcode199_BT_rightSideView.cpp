#include <iostream>
#include <vector>
#include <algorithm> // Required for std::max

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

class Solution {
public:
    /**
     * @brief Calculates the total number of levels (height) in the tree.
     */
    int levelOfTree(TreeNode* root) {
        if (root == NULL) return 0;
        int leftLevel = levelOfTree(root->left);
        int rightLevel = levelOfTree(root->right);
        return 1 + max(leftLevel, rightLevel);
    }

    /**
     * @brief A recursive helper function that performs a pre-order traversal.
     * The key insight is that for any level, the last node visited will be the
     * rightmost one. This function overwrites the value at `ans[level]`
     * as it traverses, ensuring the final value is from the rightmost node.
     * @param root The current node.
     * @param ans A reference to the result vector.
     * @param level The current level of the traversal (0-indexed).
     */
    void preOrder(TreeNode* root, vector<int>& ans, int level) {
        if (root == NULL) return;
        
        // Overwrite the value at the current level with this node's value.
        ans[level] = root->val;
        
        // Continue traversal: Left, then Right.
        preOrder(root->left, ans, level + 1);
        preOrder(root->right, ans, level + 1);
    }

    /**
     * @brief Finds the "right side view" of a binary tree.
     * @param root The root of the binary tree.
     * @return A vector of integers representing the right side view.
     */
    vector<int> rightSideView(TreeNode* root) {
        // 1. Pre-allocate the answer vector with the correct size.
        vector<int> ans(levelOfTree(root), 0);
        
        // 2. Start the pre-order traversal.
        preOrder(root, ans, 0); // Level starts from 0 for vector indexing.
        
        return ans;
    }
};

// main function to demonstrate the solution
int main() {
    // We will build the following tree:
    //      1
    //     / \
    //    2   3
    //     \   \
    //      5   4
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    // Create an instance of the Solution class
    Solution sol;

    // Get the right side view
    vector<int> result = sol.rightSideView(root);

    // Print the result
    cout << "Right Side View: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    // Expected output: 1 3 4

    return 0;
}