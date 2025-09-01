#include <iostream>
#include <vector>

// Using the standard namespace to avoid prefixing with std::
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

// The solution using the optimal in-order traversal method
class Solution {
public:
    // This is the main function that will be called.
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL; // Keeps track of the previously visited node
        bool flag = true;      // A flag to track validity, passed by reference
        
        // Start the in-order traversal
        inOrderHelper(root, prev, flag);
        
        return flag;
    }

private:
    // The helper function that performs the recursive in-order traversal.
    void inOrderHelper(TreeNode* root, TreeNode*& prev, bool& flag) {
        // Base case: if the node is null, do nothing.
        if (root == NULL) return;
        
        // 1. Traverse the left subtree first.
        inOrderHelper(root->left, prev, flag);
        
        // If a previous check has already failed, stop immediately.
        if (!flag) return;

        // 2. Process the current node.
        // Check if there's a previously visited node and if the current
        // node's value violates the BST property (it must be greater).
        if (prev != NULL && root->val <= prev->val) {
            flag = false; // Set the flag to false
            return;       // Stop the traversal
        }
        
        // If the check passes, update 'prev' to the current node for the next comparison.
        prev = root;
        
        // 3. Traverse the right subtree.
        inOrderHelper(root->right, prev, flag);
    }
};

// Main function to test the solution
int main() {
    Solution sol;

    // --- Test Case 1: A valid BST ---
    //      5
    //     / \
    //    3   8
    TreeNode* valid_root = new TreeNode(5);
    valid_root->left = new TreeNode(3);
    valid_root->right = new TreeNode(8);
    cout << "Testing a valid BST... " << endl;
    cout << "Expected: true, Got: " << boolalpha << sol.isValidBST(valid_root) << endl;
    cout << "--------------------------" << endl;

    // --- Test Case 2: An invalid BST ---
    //      10
    //     /  \
    //    5    15
    //        /
    //       6 
    TreeNode* invalid_root = new TreeNode(10);
    invalid_root->left = new TreeNode(5);
    invalid_root->right = new TreeNode(15);
    invalid_root->right->left = new TreeNode(6);
    cout << "Testing an invalid BST... " << endl;
    cout << "Expected: false, Got: " << boolalpha << sol.isValidBST(invalid_root) << endl;

    return 0;
}
