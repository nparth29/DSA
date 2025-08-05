#include <iostream>
#include <vector>
#include <queue>   // Include the queue library
#include <algorithm>
#include<climits>

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
    TreeNode* constructTree(int arr[], int n){
        TreeNode *root = new TreeNode(arr[0]);
        queue<TreeNode *> q;
        q.push(root);
        // arr[0] always be the root of tree and arr[1] and arr[2] will be left and right of root
        int i = 1;
        int j = 2;
        while(q.size() > 0 && i<n){
            TreeNode *temp = q.front();
            q.pop();
            TreeNode* l; // represetn left of root
            TreeNode *r; // represent right of root 

            // assignment 
            if(arr[i] != -1) l = new TreeNode(arr[i]);
            else l = NULL;
            if(j != n && arr[j] != -1) r = new TreeNode(arr[j]);
            else r = NULL;

            // linking
            temp->left = l;
            temp->right = r;
            // push if not null 
            if(l != NULL) q.push(l);
            if(r != NULL) q.push(r);

            i +=2;
            j +=2;
        }
        return root;
    }

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
 //-----------------------------------------------------------------------------------------
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
    int arr[] = {1, 2, 3, 4, 5, -1, 6, -1, -1, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    Solution sol;
    TreeNode *root = sol.constructTree(arr, n);
    cout << "Binary Tree Level Order Traversal using Queue: ";
    sol.levelOrderQueue(root);

    // optional :
    vector < vector<int>>result = sol.levelOrder(root);
    cout << "level vise representation: "<<endl;
    for (int i = 0; i < result.size();i++){
        cout << "[ ";
        for (int j = 0; j < result[i].size();j++){
            cout << result[i][j] << " ";
        }
        cout << " ]" << endl;
    }
}