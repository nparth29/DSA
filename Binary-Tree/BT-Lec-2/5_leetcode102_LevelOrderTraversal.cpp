#include <iostream>
#include <vector>
#include <algorithm> // Required for std::max

// Use the standard namespace for cout, vector, etc.
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
     * @brief Calculates the total number of levels (height) in the tree.
     */
    int levelOfTree(TreeNode* root) {
        if (root == NULL) return 0;
        int leftLevel = levelOfTree(root->left);
        int rightLevel = levelOfTree(root->right);
        return 1 + max(leftLevel, rightLevel);
    }

    /**
     * @brief Finds all nodes at a specific level and adds them to a vector.
     */
    void nodeAtCurrentLevel(TreeNode* root, int currentLevel, int targetLevel, vector<int>& v) {
        if (root == NULL) return;
        if (currentLevel == targetLevel) {
            v.push_back(root->val);
            return; // Optimization: no need to go deeper
        }
        nodeAtCurrentLevel(root->left, currentLevel + 1, targetLevel, v);
        nodeAtCurrentLevel(root->right, currentLevel + 1, targetLevel, v);
    }

    /**
     * @brief Helper function that iterates from level 1 to N, building the final answer.
     */
    void l_Order(TreeNode* root, vector<vector<int>>& ans) {
        if (root == NULL) return;

        // First, find the total number of levels in the tree.
        int n = levelOfTree(root);
        
        // Loop through each level from 1 to n.
        for (int i = 1; i <= n; i++) {
            vector<int> v; // Create a vector for the current level
            // Get all nodes for the current level 'i'.
            nodeAtCurrentLevel(root, 1, i, v);
            // Add this level's vector to the final answer.
            ans.push_back(v);
        }
    }

    /**
     * @brief Main function to get the level order traversal of a binary tree.
     */
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        l_Order(root, ans);
        return ans;
    }
};

// main function to demonstrate the solution
int main() {
    // We will build the following tree:
    //      1
    //     / \
    //    2   3
    //   / \ / \
    //  4  5 6  7
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Create an instance of the Solution class
    Solution sol;

    // Get the level order traversal result
    vector<vector<int>> result = sol.levelOrder(root);

    // Print the result
    cout << "Level Order Traversal:" << endl;
    for (const auto& level : result) {
        cout << "[ ";
        for (int val : level) {
            cout << val << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}

/*
================================================================================
  In-Depth Dry Run: Inefficient Level Order Traversal (LeetCode 102)
================================================================================

### The Goal
This is a trace of how the provided code performs a level-order traversal on 
the following tree. The method works by first finding the total height of the 
tree, and then looping that many times. In each loop, it re-traverses the 
entire tree from the root to find all the nodes at the current target level.

### The Sample Tree
             1
            / \
           2   3
          / \   / \
         4   5 6   7
            / \
           8   9
                \
                 10

---
### Part 1: Finding the Tree's Height

The first step in the `l_Order` function is the call to `levelOfTree(root)`.
This function works recursively, calculating the height from the bottom up.

- `levelOfTree(10)` returns 1.
- `levelOfTree(9)` gets 1 from its right child (Node 10), calculates `1 + 1 = 2`.
- `levelOfTree(8)` returns 1.
- `levelOfTree(5)` gets 1 (from Node 8) and 2 (from Node 9). It calculates `1 + max(1, 2) = 3`.
- ...and so on, up to the root.

The final call, `levelOfTree(1)`, gets a height of 4 from its left subtree (rooted at 2) 
and a height of 2 from its right subtree (rooted at 3). It calculates `1 + max(4, 2) = 5`.

Result: The variable `n` is set to 5. The main `for` loop will run for `i` from 1 to 5.

---
### Part 2: The Main Loop (`for i = 1 to 5`)

The `ans` vector is initially empty: `{}`.

#### **Iteration 1: `i = 1` (targetLevel = 1)**

1. A new empty vector `v` is created.
2. `nodeAtCurrentLevel(root=1, currentLevel=1, targetLevel=1, v)` is called.
3. **Inside the function:**
   - `currentLevel == targetLevel` (1 == 1) is TRUE.
   - `v.push_back(root->val)` adds `1`. `v` is now `{1}`.
   - The function returns.
4. The loop pushes `v` into `ans`.
   **`ans` is now `{{1}}`**.

#### **Iteration 2: `i = 2` (targetLevel = 2)**

1. A new empty vector `v` is created.
2. `nodeAtCurrentLevel(root=1, currentLevel=1, targetLevel=2, v)` is called.
3. **Trace of the calls:**
   - `(root=1, curr=1, target=2)`: Not target.
     - Calls left: `nodeAtCurrentLevel(root=2, curr=2, target=2, v)`
       - **Is target**. `v.push_back(2)`. `v` is `{2}`. Returns.
     - Calls right: `nodeAtCurrentLevel(root=3, curr=2, target=2, v)`
       - **Is target**. `v.push_back(3)`. `v` is `{2, 3}`. Returns.
4. The loop pushes `v` into `ans`.
   **`ans` is now `{{1}, {2, 3}}`**.

#### **Iteration 3: `i = 3` (targetLevel = 3)**

1. A new empty `v` is created.
2. `nodeAtCurrentLevel(root=1, currentLevel=1, targetLevel=3, v)` is called.
3. **Trace of the calls:**
   - `(1, 1, 3)` -> calls left `(2, 2, 3)`
     - `(2, 2, 3)` -> calls left `(4, 3, 3)` -> **Is target**. `v.push_back(4)`. `v` is `{4}`.
     - `(2, 2, 3)` -> calls right `(5, 3, 3)` -> **Is target**. `v.push_back(5)`. `v` is `{4, 5}`.
   - `(1, 1, 3)` -> calls right `(3, 2, 3)`
     - `(3, 2, 3)` -> calls left `(6, 3, 3)` -> **Is target**. `v.push_back(6)`. `v` is `{4, 5, 6}`.
     - `(3, 2, 3)` -> calls right `(7, 3, 3)` -> **Is target**. `v.push_back(7)`. `v` is `{4, 5, 6, 7}`.
4. The loop pushes `v` into `ans`.
   **`ans` is now `{{1}, {2, 3}, {4, 5, 6, 7}}`**.

#### **Iteration 4: `i = 4` (targetLevel = 4)**

1. A new empty `v` is created.
2. `nodeAtCurrentLevel` is called. It will traverse the tree. The only nodes it 
   will find where `currentLevel == 4` are **Node 8** and **Node 9**. The 
   traversal will find 8 first, then 9.
3. The final `v` for this iteration will be `{8, 9}`.
4. The loop pushes `v` into `ans`.
   **`ans` is now `{{1}, {2, 3}, {4, 5, 6, 7}, {8, 9}}`**.

#### **Iteration 5: `i = 5` (targetLevel = 5)**

1. A new empty `v` is created.
2. `nodeAtCurrentLevel` is called. It traverses the entire tree. The only 
   node at level 5 is **Node 10**.
3. The final `v` will be `{10}`.
4. The loop pushes `v` into `ans`.
   **`ans` is now `{{1}, {2, 3}, {4, 5, 6, 7}, {8, 9}, {10}}`**.

---
### Conclusion

The loop finishes. The final `ans` vector is returned. This detailed trace shows 
how the tree is re-traversed from the root for every single level, which is why 
the method is correct but not very efficient.
*/