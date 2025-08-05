#include <iostream>
#include <vector>
#include <queue>   // Include the queue library
#include <algorithm>

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

class Solution {
public:
    /**
     * @brief Performs level order traversal using Breadth-First Search (BFS).
     * @param root The root of the binary tree.
     * @return A 2D vector representing the level order traversal.
     */
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        // Edge case: if the tree is empty, return an empty vector.
        if (root == NULL) {
            return ans;
        }

        // 1. Initialization: Create a queue and add the root node.
        queue<TreeNode*> q;
        q.push(root);

        // 2. Loop as long as there are nodes to process.
        while (!q.empty()) {
            // 3. Process one full level.
            int size = q.size(); // Get the number of nodes on the current level.
            vector<int> currentLevel; // Vector to store this level's nodes.

            for (int i = 0; i < size; i++) {
                // Dequeue the node at the front.
                TreeNode* node = q.front();
                q.pop();

                // Process it by adding its value to the level's vector.
                currentLevel.push_back(node->val);

                // Enqueue its children (if they exist) for the next level.
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }
            // Add the completed level to the final answer.
            ans.push_back(currentLevel);
        }
        return ans;
    }

    void levelOrderQueue(TreeNode* root){
        if(root == NULL) return;
        // Create a queue to hold nodes at the current level
        queue<TreeNode*> q;
        q.push(root);
        while(q.size() >0){
            TreeNode* temp = q.front();
            q.pop();
            cout<< temp->val << " ";
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
        }
        cout << endl;
    }
};

// main function to demonstrate the solution
int main() {
    // Build the tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root);

    // Print the result
    cout << "Level Order Traversal (BFS):" << endl;
    for (const auto& level : result) {
        cout << "[ ";
        for (int val : level) {
            cout << val << " ";
        }
        cout << "]" << endl;
    }
    // Expected Output:
    // [ 1 ]
    // [ 2 3 ]
    // [ 4 5 6 7 ]

    cout << "Binary Tree Level Order Traversal using Queue: ";
    sol.levelOrderQueue(root);

    return 0;
}