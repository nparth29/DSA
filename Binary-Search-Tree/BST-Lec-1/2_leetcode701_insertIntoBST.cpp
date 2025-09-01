#include <iostream>
#include <vector>

// The TreeNode class definition you provided
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

// The Solution class containing your insertIntoBST method
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // If the tree is empty, create a new node and return it as the root.
        if (root == NULL) {
            return new TreeNode(val);
        }

        // If the value to insert is less than the current node's value,
        // recurse on the left subtree.
        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        } 
        // Otherwise, recurse on the right subtree.
        else {
            root->right = insertIntoBST(root->right, val);
        }
        
        // Return the root of the tree.
        return root;
    }
};

// Helper function to print the tree's values in sorted order (In-Order Traversal)
void printInOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    std::cout << root->val << " ";
    printInOrder(root->right);
}

// The main function to build a tree and test the insertion
int main() {
    // Create an instance of the Solution class
    Solution sol;

    // Build an initial BST:
    //      4
    //     / \
    //    2   7
    //   / \
    //  1   3
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    std::cout << "Original tree (in-order): ";
    printInOrder(root);
    std::cout << std::endl;

    // Define the value to insert
    int value_to_insert = 5;
    std::cout << "Inserting value: " << value_to_insert << std::endl;

    // Call the insertIntoBST method
    root = sol.insertIntoBST(root, value_to_insert);

    std::cout << "   Updated tree (in-order): ";
    printInOrder(root);
    std::cout << std::endl;

    return 0;
}