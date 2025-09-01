#include <iostream>
#include <vector>

// 1. Definition for a binary tree node.
// This struct defines what each node in our tree looks like.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    // Constructor to easily create a new node
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 2. Helper function to insert new nodes into the BST.
// This function places the new value in its correct spot in the tree.
TreeNode* insert(TreeNode* root, int val) {
    // If the tree is empty, create a new node and return it as the new root.
    if (root == NULL) {
        return new TreeNode(val);
    }
    // If the value is less than the root's value, insert it in the left subtree.
    if (val < root->val) {
        root->left = insert(root->left, val);
    } 
    // If the value is greater than the root's value, insert it in the right subtree.
    else if (val > root->val) {
        root->right = insert(root->right, val);
    }
    // Return the (possibly updated) root pointer.
    return root;
}

// 3. The Solution class with your searchBST method.
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // Base Cases: If the root is null or the root's value is what we are looking for.
        if (root == NULL || root->val == val) {
            return root;
        }
        
        // If the value to find is less than the root's value, search in the left subtree.
        if (root->val > val) {
            return searchBST(root->left, val);
        } 
        // Otherwise, the value must be greater, so search in the right subtree.
        else { 
            return searchBST(root->right, val);
        }
    }
};

// 4. The main function to execute the code.
int main() {
    // Create an instance of the Solution class.
    Solution sol;

    // Create the root of our tree. It starts as empty (NULL).
    TreeNode* root = NULL;

    // Values to insert into the tree to build our example BST.
    std::vector<int> values = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    
    // Insert each value into the tree.
    for (int val : values) {
        root = insert(root, val);
    }
    
    // --- Test Case 1: Search for a value that exists ---
    int value_to_find_1 = 6;
    std::cout << "Searching for value: " << value_to_find_1 << std::endl;
    TreeNode* result_node_1 = sol.searchBST(root, value_to_find_1);

    if (result_node_1 != NULL) {
        std::cout << "Found value: " << result_node_1->val << std::endl;
    } else {
        std::cout << "Value not found." << std::endl;
    }

    std::cout << "--------------------------" << std::endl;

    // --- Test Case 2: Search for a value that does NOT exist ---
    int value_to_find_2 = 5;
    std::cout << "Searching for value: " << value_to_find_2 << std::endl;
    TreeNode* result_node_2 = sol.searchBST(root, value_to_find_2);

    if (result_node_2 != NULL) {
        std::cout << "Found value: " << result_node_2->val << std::endl;
    } else {
        std::cout << "Value not found." << std::endl;
    }

    return 0;
}