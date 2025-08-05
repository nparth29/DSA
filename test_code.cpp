#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;

        // 1. The Queue: Our main tool for BFS.
        queue<TreeNode*> q;
        q.push(root);

        // 2. The Main Loop: Runs as long as there are nodes to process.
        while (!q.empty()) {
            
            // 3. The "Magic" Step: Get the size of the current level.
            int levelSize = q.size(); 
            vector<int> currentLevel;

            // 4. The Inner Loop: Process exactly 'levelSize' nodes.
            for (int i = 0; i < levelSize; i++) {
                
                // 5. Dequeue: Get the node at the front.
                TreeNode* node = q.front();
                q.pop();

                // 6. Process Node: Add its value to the current level's list.
                currentLevel.push_back(node->val);

                // 7. Enqueue Children: Add children to the queue for the next level.
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }
            
            // 8. Add Level to Result: Add the completed level to our final answer.
            ans.push_back(currentLevel); 
        }
        return ans;
    }
};