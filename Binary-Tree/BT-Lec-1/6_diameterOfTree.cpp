#include <iostream>
#include <algorithm> // Required for std::max

// Use the standard namespace for cout, max, etc.
using namespace std;

// Definition for a binary tree node.
class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val){
        this->val = val;
        this->left = NULL; 
        this->right = NULL; 
 }
};

// Your provided Solution class
class Solution {
public:
    /**
     * @brief Calculates the height (number of nodes on the longest path) of a subtree.
     * @param root The root of the subtree.
     * @return The height of the subtree.
     */
    int levels(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }

    /**
     * @brief A helper function to traverse every node and calculate the diameter at that node.
     * It updates the overall maximum diameter found so far.
     * @param root The current node.
     * @param maxDia A reference to the variable holding the maximum diameter.
     */
    void helper(TreeNode* root, int &maxDia){
        if(root == NULL) return;
        
        // The diameter at the current node is the height of the left subtree
        // plus the height of the right subtree.
        int dia = levels(root->left) + levels(root->right);
        maxDia = max(maxDia, dia);
        
        // Recursively check the rest of the nodes.
        helper(root->left, maxDia);
        helper(root->right, maxDia);
    }

    /**
     * @brief Calculates the diameter of a binary tree.
     * * The diameter is the length of the longest path between any two nodes in a tree.
     * This path may or may not pass through the root.
     * * @param root The root of the binary tree.
     * @return The diameter of the tree.
     */
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;
        helper(root, maxDia);
        return maxDia;
    }
};

// main function to demonstrate a case where the diameter does not pass through the root
int main() {
    // We will build the following tree:
    //         1
    //        / 
    //       2
    //      /
    //     3 <--- The diameter is centered here
    //    / \
    //   4   5
    //  /     \
    // 6       7
    //          \
    //           8

    // In this tree:
    // - The path through the root (1) is short.
    // - The longest path is 6 -> 4 -> 3 -> 5 -> 7 -> 8.
    // - This path has 5 edges, so the diameter is 5.
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    root->left->left = node3;
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    node3->left = node4;
    node3->right = node5;
    node4->left = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);
    node5->right = node7;
    node7->right = new TreeNode(8);

    // Create an instance of the Solution class
    Solution sol;

    // Calculate the diameter
    int diameter = sol.diameterOfBinaryTree(root);

    // Print the result
    cout << "The diameter of the tree is: " << diameter << endl; // Expected output: 5

    return 0;
}