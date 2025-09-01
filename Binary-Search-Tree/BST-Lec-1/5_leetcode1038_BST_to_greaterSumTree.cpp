#include <iostream>
#include <vector>

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

// Your Solution class with the corrected logic
class Solution {
public:
    // This is the main function to be called
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0; 
        // Start the reverse in-order traversal with an initial sum of 0
        inOrder(root, sum); 
        return root;
    }

private:
    // Helper function to perform the reverse in-order traversal
    void inOrder(TreeNode* root, int &sum) {
        // Base case: stop if the node is null
        if (root == NULL) return;

        // 1. Traverse the right subtree first (to get to the largest values)
        inOrder(root->right, sum);
        
        // 2. Process the current node:
        //    - Add the node's original value to the running sum.
        //    - Update the node's value to this new sum.
        sum = sum + root->val;
        root->val = sum;
        
        // 3. Traverse the left subtree (which will now use the updated sum)
        inOrder(root->left, sum);
    }
};

// Helper function to print the tree using standard in-order traversal
void printInOrder(TreeNode* root) {
    if (root == NULL) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

// Main function to build a tree and test the solution
int main() {
    Solution sol;

    // Build a sample Binary Search Tree:
    //      4
    //     / \
    //    1   6
    //   / \ / \
    //  0  2 5  7
    //     \     \
    //      3     8
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(3);
    root->right = new TreeNode(6);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(8);

    cout << "Original tree (in-order): ";
    printInOrder(root);
    cout << endl;

    // Transform the tree
    sol.bstToGst(root);

    cout << "Greater Sum Tree (in-order): ";
    printInOrder(root);
    cout << endl;

    return 0;
}
