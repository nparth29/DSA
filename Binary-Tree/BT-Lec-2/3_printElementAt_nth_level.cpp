#include <iostream>

// Use the standard namespace for cout, etc.
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

/**
 * @brief Prints all nodes at a specific target level.
 * @param root The current node in the traversal.
 * @param currentLevel The level of the current node (starts at 1 for the root).
 * @param targetLevel The level we want to print nodes from.
 */
void printNodesAtLevel(TreeNode* root, int currentLevel, int targetLevel) {
    // Base Case 1: If the node is NULL, there's nothing to do.
    if (root == NULL) {
        return;
    }

    // Base Case 2: If we've reached the target level, print the value.
    if (currentLevel == targetLevel) {
        cout << root->val << " ";
        // We can return here as an optimization, since children would be on a deeper level.
        return;
    }

    // Recursive Step: Continue the pre-order traversal, incrementing the current level.
    printNodesAtLevel(root->left, currentLevel + 1, targetLevel);
    printNodesAtLevel(root->right, currentLevel + 1, targetLevel);
}

// main function to demonstrate the solution
int main() {
    // We will build the following tree:
    // Level 1:      1
    // Level 2:     / \
    //             2   3
    // Level 3:   / \ / \
    //           4  5 6  7
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // --- Test Case ---
    int levelToPrint = 3;
    cout << "Nodes at level " << levelToPrint << ": ";
    printNodesAtLevel(root, 1, levelToPrint);
    cout << endl; // Expected output: 4 5 6 7

    // --- Another Test Case ---
    levelToPrint = 2;
    cout << "Nodes at level " << levelToPrint << ": ";
    printNodesAtLevel(root, 1, levelToPrint);
    cout << endl; // Expected output: 2 3

    return 0;
}