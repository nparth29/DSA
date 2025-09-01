#include <iostream>
#include <vector>
#include <queue> // Used for level-order printing

// Using the standard namespace for cleaner code
using namespace std;

// The TreeNode class definition
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
    // Helper function to insert a node into the BST
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            return new TreeNode(val);
        }

        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        } else {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }

    // Main function to construct the BST from a preorder traversal
    TreeNode* bstFromPreorder(vector<int>& pre) {
        if (pre.empty()) {
            return NULL;
        }
        
        // The first element of a preorder traversal is always the root
        TreeNode* root = new TreeNode(pre[0]);
        
        // Iterate through the rest of the elements and insert them into the tree
        for(size_t i = 1; i < pre.size(); i++){
            insertIntoBST(root, pre[i]);
        }
        return root;
    }
};

// Helper function to print the tree in-order to verify it's a correct BST
void printInOrder(TreeNode* root) {
    if (root == NULL) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

// Main function to test the solution
int main() {
    Solution sol;

    // A sample preorder traversal array
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    cout << "Original preorder array: ";
    for (int num : preorder) {
        cout << num << " ";
    }
    cout << endl << endl;

    // Construct the BST
    TreeNode* root = sol.bstFromPreorder(preorder);

    cout << "Resulting BST (In-Order Traversal):" << endl;
    printInOrder(root);
    cout << endl;

    return 0;
}
