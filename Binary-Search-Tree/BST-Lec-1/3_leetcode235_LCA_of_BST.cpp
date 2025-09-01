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

// Your Solution class for finding LCA in a BST
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: If root is null, return null.
        if (root == NULL) {
            return NULL;
        }

        // Case 1: The current root's value is one of the targets.
        // If so, the root must be the LCA.
        if (root->val == p->val || root->val == q->val) {
            return root;
        }

        // Case 2: The nodes are "split" by the current root.
        // p is in the left subtree and q is in the right.
        if (root->val > p->val && root->val < q->val) {
            return root;
        }

        // Case 3: The nodes are "split" by the current root (the other way).
        // q is in the left subtree and p is in the right.
        if (root->val < p->val && root->val > q->val) {
            return root;
        }

        // Case 4: Both p and q are smaller than the current root's value.
        // The LCA must be in the left subtree.
        if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        
        // Case 5: Both p and q are larger than the current root's value.
        // The LCA must be in the right subtree.
        // This is the final "else" case.
        else {
            return lowestCommonAncestor(root->right, p, q);
        }
    }
};

// The main function to build a tree and test the solution
int main() {
    // Build a sample Binary Search Tree:
    //      6
    //     / \
    //    2   8
    //   / \ / \
    //  0  4 7  9
    //    / \
    //   3   5
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    Solution sol;

    // --- Test Case 1: Nodes are on opposite sides of the root ---
    TreeNode* p1 = root->left;        // Node 2
    TreeNode* q1 = root->right;       // Node 8
    TreeNode* lca1 = sol.lowestCommonAncestor(root, p1, q1);
    std::cout << "Test Case 1:" << std::endl;
    std::cout << "LCA of " << p1->val << " and " << q1->val << " is: " << lca1->val << std::endl;
    std::cout << "--------------------------" << std::endl;

    // --- Test Case 2: Nodes are in the same subtree ---
    TreeNode* p2 = root->left->right->left;   // Node 3
    TreeNode* q2 = root->left->right->right;  // Node 5
    TreeNode* lca2 = sol.lowestCommonAncestor(root, p2, q2);
    std::cout << "Test Case 2:" << std::endl;
    std::cout << "LCA of " << p2->val << " and " << q2->val << " is: " << lca2->val << std::endl;

    return 0;
}
