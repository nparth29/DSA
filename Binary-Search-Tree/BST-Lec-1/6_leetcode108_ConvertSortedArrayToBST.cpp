#include <iostream>
#include <vector>
#include <queue> // Used for level-order printing

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

// Your Solution class with the corrected logic
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& arr) {
        int n = arr.size();
        // Initial call to the recursive helper function
        return helper(arr, 0, n - 1);
    }

private:
    // Recursive helper to build the tree from a subarray
    TreeNode* helper(vector<int>& arr, int lo, int hi) {
        // Base case: If the range is invalid, this is a null leaf
        if (lo > hi) return NULL;
        
        // Find the middle element of the current subarray
        // This will become the root of the current subtree
        int mid = lo + (hi - lo) / 2;
        TreeNode* root = new TreeNode(arr[mid]);
        
        // Recursively build the left subtree from the left half of the array
        root->left = helper(arr, lo, mid - 1);
        
        // Recursively build the right subtree from the right half of the array
        root->right = helper(arr, mid + 1, hi);
        
        return root;
    }
};

// Helper function to print the tree level by level to show its structure
void printLevelOrder(TreeNode* root) {
    if (root == NULL) {
        cout << "Tree is empty." << endl;
        return;
    }
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        
        if (current == NULL) {
            cout << "null ";
            continue;
        }
        
        cout << current->val << " ";
        q.push(current->left);
        q.push(current->right);
    }
    cout << endl;
}

// Main function to test the solution
int main() {
    Solution sol;

    // The sorted array to convert
    vector<int> arr = {-10, -3, 0, 5, 9};

    cout << "Original sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl << endl;

    // Convert the array to a BST
    TreeNode* root = sol.sortedArrayToBST(arr);

    cout << "Resulting BST (Level-Order Traversal):" << endl;
    printLevelOrder(root);

    return 0;
}
