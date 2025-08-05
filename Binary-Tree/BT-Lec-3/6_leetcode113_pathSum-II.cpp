#include <iostream>
#include <vector>
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
    /**
     * @brief A recursive helper function to find all valid root-to-leaf paths.
     * @param root The current node.
     * @param v The path built so far (passed by value).
     * @param ans The final list of paths (passed by reference).
     * @param sum The remaining sum needed to reach the target.
     */
    void helper(TreeNode* root, vector<int> v, vector<vector<int>>& ans, int sum) {
        // Base case: If the node is NULL, this path is invalid.
        if (root == NULL) {
            return;
        }

        // Add the current node's value to the path for this branch.
        // Since 'v' is a copy, this doesn't affect other branches.
        v.push_back(root->val);

        // Check if the current node is a leaf.
        if (root->left == NULL && root->right == NULL) {
            // If it's a leaf, check if its value completes the sum.
            if (root->val == sum) {
                // If the sum is correct, this is a valid path. Add it to the answer.
                ans.push_back(v);
            }
            // Stop exploring this path since we're at a leaf.
            return;
        }

        // Recursive step for non-leaf nodes.
        // Explore the left and right children. A new copy of 'v' is created for each call.
        helper(root->left, v, ans, sum - root->val);
        helper(root->right, v, ans, sum - root->val);
    }

    /**
     * @brief Finds all root-to-leaf paths where the sum of nodes equals targetSum.
     * @param root The root of the binary tree.
     * @param targetSum The target sum to find.
     * @return A 2D vector containing all valid paths.
     */
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        // Start the recursive process.
        helper(root, v, ans, targetSum);
        return ans;
    }
};

// main function to demonstrate the solution
int main() {
    // LeetCode example tree:
    //      5
    //     / \
    //    4   8
    //   /   / \
    //  11  13  4
    // /  \    / \
    // 7   2  5   1
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;

    // Create an instance of the Solution class
    Solution sol;

    // Get the list of all valid paths
    vector<vector<int>> result = sol.pathSum(root, targetSum);

    // Print the results
    cout << "Paths with sum " << targetSum << ":" << endl;
    for (const auto& path : result) {
        cout << "[ ";
        for (int val : path) {
            cout << val << " ";
        }
        cout << "]" << endl;
    }
    // Expected Output:
    // [ 5 4 11 2 ]
    // [ 5 8 4 5 ]
    
    return 0;
}