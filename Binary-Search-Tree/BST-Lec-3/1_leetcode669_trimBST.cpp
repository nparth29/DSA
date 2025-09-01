#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
#include <limits> // For std::numeric_limits


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

// Your Solution class with added comments
class Solution {
public:
    /**
     * Helper function that recursively trims the tree.
     * It ensures that the immediate children of the current 'root' are within
     * the [lo, hi] range, and then recursively calls itself on those children.
     */
    void trim(TreeNode* root, int lo, int hi) {
        if (root == NULL) return;

        // --- Step 1: Adjust the left child pointer ---
        // This loop ensures that root->left is either NULL or points to a
        // node with a value inside the valid [lo, hi] range.
        while (root->left != NULL) {
            // If the left child's value is too low, we know its entire
            // left subtree is also too low. So, we replace the left child
            // with its own right child.
            if (root->left->val < lo) {
                root->left = root->left->right;
            }
            // If the left child's value is too high, we know its entire
            // right subtree is also too high. So, we replace the left child
            // with its own left child.
            else if (root->left->val > hi) {
                root->left = root->left->left;
            }
            // If the left child is within the valid range, we stop adjusting.
            else {
                break;
            }
        }
        
        // --- Step 2: Adjust the right child pointer ---
        // This loop does the same for the right child, ensuring it's valid.
        while (root->right != NULL) {
            // If the right child's value is too high, its right subtree is
            // also too high. Replace it with its own left child.
            if (root->right->val > hi) {
                root->right = root->right->left;
            }
            // If the right child's value is too low, its left subtree is
            // also too low. Replace it with its own right child.
            else if (root->right->val < lo) {
                root->right = root->right->right;
            }
            // If the right child is valid, stop.
            else {
                break;
            }
        }

        // --- Step 3: Recurse on the now-valid children ---
        // After ensuring the immediate children are correct, we recursively
        // call trim on them to fix their own subtrees.
        trim(root->left, lo, hi);
        trim(root->right, lo, hi);
    }

    /**
     * Main function to trim a BST.
     * It creates a dummy node to simplify handling cases where the
     * original root itself needs to be removed.
     */
    TreeNode* trimBST(TreeNode* root, int lo, int hi) {
        // Create a dummy node whose value is outside any expected range.
        // Its left child points to the real root of the tree.

        // TreeNode* dummy = new TreeNode(INT_MAX);
        TreeNode* dummy = new TreeNode(std::numeric_limits<int>::max());

        dummy->left = root;
        
        // Call the helper function on the dummy node.
        // This allows the 'trim' logic to potentially change the real root.
        trim(dummy, lo, hi);
        
        // The dummy's left child now points to the root of the final, trimmed tree.
        return dummy->left;
    }
};

// Helper function to print the tree in-order
void printInOrder(TreeNode* root) {
    if (root == NULL) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

// Main function to test the solution
int main() {
    Solution sol;

    // Build a sample BST:
    //      8
    //     / \
    //    3   10
    //   / \    \
    //  1   6    14
    //     / \
    //    4   7
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    root->right = new TreeNode(10);
    root->right->right = new TreeNode(14);

    cout << "Original tree (in-order): ";
    printInOrder(root);
    cout << endl;

    int low = 5;
    int high = 13;
    cout << "Trimming the tree to the range [" << low << ", " << high << "]..." << endl;

    // Trim the BST
    TreeNode* trimmedRoot = sol.trimBST(root, low, high);

    cout << "Trimmed tree (in-order):  ";
    printInOrder(trimmedRoot);
    cout << endl;

    return 0;
}
