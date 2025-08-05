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

    /**
     * @brief Helper function that iterates from level 1 to N, building the final answer.
     */
    void l_Order(TreeNode* root, vector<vector<int>>& ans,int level) {
        if (root == NULL) return;
        // work
        ans[level].push_back(root->val);
        l_Order(root->left, ans, level + 1);
        l_Order(root->right, ans, level + 1);
    }

    /**
     * @brief Main function to get the level order traversal of a binary tree.
     */
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int n = levelOfTree(root);
        for (int i = 0; i < n;i++){
            vector<int> v;
            ans.push_back(v);
        }
        l_Order(root, ans, 0); // its vector so level starts from 0 to match with indexing of vector
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

    Solution sol;

    vector<vector<int>> result = sol.levelOrder(root);

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