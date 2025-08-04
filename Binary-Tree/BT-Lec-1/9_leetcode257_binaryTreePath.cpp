#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Definition for a binary tree node, as we've been using.
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
     * @brief A recursive helper function to perform a pre-order traversal
     * and build the path strings.
     * @param root The current node in the traversal.
     * @param s The path string built so far from the root to the current node's parent.
     * @param ans A reference to the vector that will store the final path strings.
     */
    void helper(TreeNode* root, string s, vector<string>& ans) {
        // Base case: If the node is NULL, this path ends. Do nothing.
        if (root == NULL) {
            return;
        }

        // Convert the current node's integer value to a string.
        string a = to_string(root->val);

        // Check if the current node is a leaf node (no children).
        if (root->left == NULL && root->right == NULL) {
            // If it's a leaf, the path is complete.
            // Append the leaf node's value to the path string.
            s += a;
            // Add the completed path to our answer vector.
            ans.push_back(s);
            return;
        }

        // Recursive Step: If it's not a leaf node, continue the traversal.
        // Explore the left child, passing down the updated path string.
        helper(root->left, s + a + "->", ans);
        // Explore the right child, passing down the updated path string.
        helper(root->right, s + a + "->", ans);
    }

    /**
     * @brief Finds all root-to-leaf paths in a binary tree.
     * @param root The root of the binary tree.
     * @return A vector of strings, where each string is a root-to-leaf path.
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        // Create a vector to store the string answers.
        vector<string> ans;
        // Start the recursive helper function. The initial path string is empty.
        helper(root, "", ans);
        // Return the final list of paths.
        return ans;
    }
};

// main function to build a tree and test the solution
int main() {
    // We will build the following tree:
    //      1
    //     / \
    //    2   3
    //     \
    //      5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    // Create an instance of the Solution class.
    Solution sol;

    // Get the list of all root-to-leaf paths.
    vector<string> paths = sol.binaryTreePaths(root);

    // Print the results.
    cout << "The root-to-leaf paths are:" << endl;
    for (const string& path : paths) {
        cout << "- " << path << endl;
    }
    // Expected output:
    // - 1->2->5
    // - 1->3

    return 0;
} 