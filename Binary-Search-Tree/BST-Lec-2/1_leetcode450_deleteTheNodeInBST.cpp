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

// Your Solution class with improved comments
class Solution {
public:
    /**
     * Finds the in-order predecessor of a given node.
     * The predecessor is the largest value in the node's left subtree.
     */
    TreeNode* findPredecessor(TreeNode* root) {
        TreeNode* pred = root->left;
        while (pred->right != NULL) {
            pred = pred->right;
        }
        return pred;
    }

    /**
     * Finds the in-order successor of a given node.
     * The successor is the smallest value in the node's right subtree.
     */
    TreeNode* findSuccessor(TreeNode* root) {
        TreeNode* suc = root->right;
        while (suc->left != NULL) {
            suc = suc->left;
        }
        return suc;
    }

    /**
     * Deletes a node with the given key from the BST.
     * Returns the root of the modified subtree.
     */
    TreeNode* deleteNode(TreeNode* root, int key) {
        // Base case: If the tree is empty, there's nothing to delete.
        if (root == NULL) return NULL;

        // --- Step 1: Find the node to delete ---
        if (key < root->val) {
            // The key is in the left subtree.
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            // The key is in the right subtree.
            root->right = deleteNode(root->right, key);
        } else {
            // This is the node to be deleted (root->val == key).
            // --- Step 2: Handle the three deletion cases ---

            // Case 1: The node is a leaf (0 children).
            if (root->left == NULL && root->right == NULL) {
                delete root; // Free the memory
                return NULL; // The parent's child pointer will become NULL.
            }

            // Case 2: The node has exactly one child.
            // This 'if' is only reached if Case 1 is false, meaning the node
            // must have at least one child. The OR condition checks for this.
            if (root->left == NULL || root->right == NULL) {
                TreeNode* child;
                if (root->left != NULL) {
                    child = root->left;
                } else { // This means root->right must not be NULL.
                    child = root->right;
                }
                delete root; // Free the memory
                return child; // The child replaces the deleted node.
            }

            // Case 3: The node has two children.
            if (root->left != NULL && root->right != NULL) {
                // Find the in-order successor (the smallest node in the right subtree).
                TreeNode* successor = findSuccessor(root);
                
                // Copy the successor's value to this node.
                root->val = successor->val;
                
                // Recursively delete the successor node from the right subtree.
                // This is guaranteed to be a Case 1 or Case 2 deletion.
                root->right = deleteNode(root->right, successor->val);
            }
        }
        
        // Return the (possibly modified) root of the current subtree.
        return root;
    }
};

// Helper function to print the tree in-order to verify its structure
void printInOrder(TreeNode* root) {
    if (root == NULL) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

// Main function to test the deletion logic
int main() {
    Solution sol;

    // Build a sample Binary Search Tree:
    //      8
    //     / \
    //    3   10
    //   / \    \
    //  1   6    14
    //     / \   /
    //    4   7 13
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    root->right = new TreeNode(10);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    cout << "Original tree (in-order): ";
    printInOrder(root);
    cout << endl << endl;

    // --- Test Case 1: Delete a leaf node (7) ---
    cout << "Deleting leaf node 7..." << endl;
    root = sol.deleteNode(root, 7);
    cout << "Tree after deleting 7:    ";
    printInOrder(root);
    cout << endl << endl;

    // --- Test Case 2: Delete a node with one child (10) ---
    cout << "Deleting node 10 (has one child)..." << endl;
    root = sol.deleteNode(root, 10);
    cout << "Tree after deleting 10:   ";
    printInOrder(root);
    cout << endl << endl;

    // --- Test Case 3: Delete a node with two children (3) ---
    cout << "Deleting node 3 (has two children)..." << endl;
    root = sol.deleteNode(root, 3);
    cout << "Tree after deleting 3:    ";
    printInOrder(root);
    cout << endl << endl;

    return 0;
}
