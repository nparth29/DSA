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

// Your corrected Solution class
class Solution {
public:
    TreeNode* build(vector<int>& pre, int prelo, int prehi, vector<int>& in, int inlo, int inhi) {
        // Base case: If the subarray is empty, there is no node to create.
        if (prelo > prehi) return NULL;

        // The first element in the preorder subarray is always the root of the current subtree.
        TreeNode* root = new TreeNode(pre[prelo]);

        // Find the root's position in the inorder subarray.
        // Elements to the left are in the left subtree, elements to the right are in the right subtree.
        int i = inlo;
        while (i <= inhi) {
            if (in[i] == pre[prelo]) break;
            i++;
        }

        // Calculate the number of nodes in the left subtree.
        int leftCount = i - inlo;

        // Recursively build the left and right subtrees using the calculated boundaries.
        // Left subtree
        root->left = build(pre, prelo + 1, prelo + leftCount, in, inlo, i - 1);
        // Right subtree
        root->right = build(pre, prelo + leftCount + 1, prehi, in, i + 1, inhi);

        return root;
    }

    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = pre.size();
        if (n == 0) return NULL;
        return build(pre, 0, n - 1, in, 0, n - 1);
    }
};

// Helper function to print the tree (in-order) to verify it's correct
void printInOrder(TreeNode* root) {
    if (root == NULL) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

// main function to demonstrate the solution
int main() {
    // LeetCode Example Test Case:
    // Preorder: Root -> Left -> Right
    // Inorder:  Left -> Root -> Right
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    // Create an instance of the Solution class
    Solution sol;

    // Construct the tree
    TreeNode* root = sol.buildTree(preorder, inorder);

    // Print the constructed tree's in-order traversal to verify correctness.
    // The output should match the original 'inorder' vector.
    cout << "In-order traversal of the constructed tree: ";
    printInOrder(root);
    cout << endl;
    // Expected Output: 9 3 15 20 7

    return 0;
}
