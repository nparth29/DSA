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
     * @brief Finds all nodes at a specific level and adds them to a vector.
     */
    void nodeAtCurrentLevel(TreeNode* root, int currentLevel, int targetLevel, vector<int>& v) {
        if (root == NULL) return;
        if (currentLevel == targetLevel) {
            v.push_back(root->val);
            return; // Optimization: no need to go deeper
        }
        nodeAtCurrentLevel(root->left, currentLevel + 1, targetLevel, v);
        nodeAtCurrentLevel(root->right, currentLevel + 1, targetLevel, v);
    }

    /**
     * @brief Helper function that iterates from level 1 to N, building the final answer.
     */
    void l_Order(TreeNode* root, vector<vector<int>>& ans) {
        if (root == NULL) return;

        // First, find the total number of levels in the tree.
        int n = levelOfTree(root);
        
        // Loop through each level from 1 to n.
        for (int i = 1; i <= n; i++) {
            vector<int> v; // Create a vector for the current level
            // Get all nodes for the current level 'i'.
            nodeAtCurrentLevel(root, 1, i, v);
            // Add this level's vector to the final answer.
            ans.push_back(v);
        }
    }

    /**
     * @brief Main function to get the level order traversal of a binary tree.
     */
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        l_Order(root, ans);
        return ans;
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

    // Get the level order traversal result
    vector<vector<int>> result = sol.levelOrder(root);

    // Print the result
    cout << "Level Order Traversal:" << endl;
    for (const auto& level : result) {
        cout << "[ ";
        for (int val : level) {
            cout << val << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}