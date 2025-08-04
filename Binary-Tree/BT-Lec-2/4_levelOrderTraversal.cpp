#include <iostream>
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

int Level(TreeNode* node) {
    if (node == NULL) {
        return 0; // Base case: if the node is NULL, return the smallest integer
    }
    // Recursive case: find the maximum level in the left and right subtrees
    int leftLevel = Level(node->left);
    int rightLevel = Level(node->right);
    // Return the maximum of the current node's level and the levels from its children
    return 1 + max(leftLevel, rightLevel);

}  

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

void levleOrderTraversal(TreeNode* root){
    if(root == NULL)
        return;
    int n = Level(root);
    for (int i = 0; i < n;i++){
        cout << "Nodes at level " << i + 1 << ": ";
        printNodesAtLevel(root, 1, i+1);
        cout << endl; // Print a newline for better readability
    }
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

    // Display the tree
    cout << "Binary Tree Level Order Traversal:" << endl;
    levleOrderTraversal(root);

    return 0;
}