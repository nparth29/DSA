// we have to find the sum of all nodes in a binary tree
// we will use recursion to do this
#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node(int val) {
        this->val = val;
        this->left = NULL; 
        this->right = NULL; 
    }
};

int sum(Node* node) {
    if (node == NULL) {
        return 0; // Base case: if the node is NULL, return 0
    }
    // Recursive case: sum the value of the current node and the sums of its left and right children
    return node->val + sum(node->left) + sum(node->right);
}   

int main(){
    // Example usage of the Node class
    Node *root = new Node(1);
    Node *leftChild = new Node(2);
    Node *rightChild = new Node(3);
    Node *leftLeftChild = new Node(4);
    Node *leftRightChild = new Node(5);
    Node *rightLeftChild = new Node(6);
    Node *rightRightChild = new Node(7);

    // connections 
    root->left = leftChild;
    root->right = rightChild;   
    leftChild->left = leftLeftChild;
    leftChild->right = leftRightChild;
    rightChild->left = rightLeftChild;
    rightChild->right = rightRightChild;

    // Display the tree
    cout << "Binary Tree: ";
    int s = sum(root);
    cout << "Sum of all nodes: " << s << endl;
    
    return 0;
}

/*
================================================================================
  Sum of Nodes: Dry Run Visualization
================================================================================

The `sum` function uses a post-order traversal logic. For any given node,
it must wait for the results from its left and right children before it can
calculate and return its own total sum. The process builds from the leaves up.

--------------------------------------------------------------------------------

Initial Call: `sum(root)` is called from `main`. The function immediately
drills down the left side to find a leaf node to start summing from.

`sum(1)` calls `sum(2)`, which calls `sum(4)`.

Current Call Stack:
sum(4)  <-- Current task
sum(2)
sum(1)

--------------------------------------------------------------------------------

Step 1: The First Return (from a leaf)

- At Node 4: The call to `sum(4)` is at the top of the stack.
  - It calls `sum(left)`, which is `sum(NULL)` -> returns 0.
  - It calls `sum(right)`, which is `sum(NULL)` -> returns 0.
  - It calculates its total: `4 + 0 + 0 = 4`.
  - `sum(4)` is done and returns the value `4` to its caller (`sum(2)`).

--------------------------------------------------------------------------------

Step 2: Processing the Left Subtree

- At Node 2: `sum(2)` has received `4` from its left side.
  - It now calls `sum(right)`, which is `sum(5)`.
  - The `sum(5)` call calculates `5 + 0 + 0` and returns `5`.
- `sum(2)` now has all the required values:
  - Its own value: 2
  - From left child: 4
  - From right child: 5
  - It calculates the subtree total: `2 + 4 + 5 = 11`.
  - `sum(2)` is done and returns `11` to its caller (`sum(1)`).

--------------------------------------------------------------------------------

Step 3: Processing the Right Subtree

- At Node 1: `sum(1)` has received `11` from its left side.
  - It now calls `sum(right)`, which is `sum(3)`.
- This triggers the same process for the right subtree:
  - `sum(3)` calls `sum(6)`, which returns `6`.
  - `sum(3)` calls `sum(7)`, which returns `7`.
- `sum(3)` now has all the required values:
  - Its own value: 3
  - From left child: 6
  - From right child: 7
  - It calculates the subtree total: `3 + 6 + 7 = 16`.
  - `sum(3)` is done and returns `16` to its caller (`sum(1)`).

--------------------------------------------------------------------------------

Step 4: The Grand Total

- At Node 1: `sum(1)` is at the top of the stack again. It has everything it needs.
  - Its own value: 1
  - From left child (`sum(2)`): 11
  - From right child (`sum(3)`): 16
  - It calculates the grand total: `1 + 11 + 16 = 28`.
  - `sum(1)` returns `28` to the `main` function.

The call stack is now empty.

Final Result: 28
================================================================================
*/