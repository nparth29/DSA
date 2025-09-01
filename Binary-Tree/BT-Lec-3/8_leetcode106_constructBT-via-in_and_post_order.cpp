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

// Your Solution class
class Solution {
public:
    TreeNode* build(vector<int>& post, int postlo, int posthi, vector<int>& in, int inlo, int inhi) {
        // Base case: If the subarray is empty, there is no node to create.
        if (postlo > posthi) return NULL;

        // The last element in the postorder subarray is the root of the current subtree.
        TreeNode* root = new TreeNode(post[posthi]);

        // Find the root's position in the inorder subarray.
        int i = inlo;
        while (i <= inhi) {
            if (in[i] == post[posthi]) break;
            i++;
        }

        // Calculate the number of nodes in the left subtree.
        int leftCount = i - inlo;

        // Recursively build the left and right subtrees.
        // The boundaries for the postorder array are calculated based on the leftCount.
        root->left = build(post, postlo, postlo + leftCount - 1, in, inlo, i - 1);
        root->right = build(post, postlo + leftCount, posthi - 1, in, i + 1, inhi);

        return root;
    }

    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n = post.size();
        if (n == 0) return NULL;
        return build(post, 0, n - 1, in, 0, n - 1);
    }
};

// Helper function to print the tree (pre-order) to verify it's correct
void printPreOrder(TreeNode* root) {
    if (root == NULL) return;
    cout << root->val << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

// main function to demonstrate the solution
int main() {
    // LeetCode Example Test Case:
    // Inorder:  Left -> Root -> Right
    // Postorder: Left -> Right -> Root
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    // Create an instance of the Solution class
    Solution sol;

    // Construct the tree
    TreeNode* root = sol.buildTree(inorder, postorder);

    // Print the constructed tree's pre-order traversal to verify correctness.
    // The expected pre-order for this tree is {3, 9, 20, 15, 7}
    cout << "Pre-order traversal of the constructed tree: ";
    printPreOrder(root);
    cout << endl;
    // Expected Output: 3 9 20 15 7

    return 0;
}
