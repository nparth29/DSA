// we hve to find the level and height of a binary tree

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

int Level(Node* node) {
    if (node == NULL) {
        return 0; // Base case: if the node is NULL, return the smallest integer
    }
    // Recursive case: find the maximum level in the left and right subtrees
    int leftLevel = Level(node->left);
    int rightLevel = Level(node->right);
    // Return the maximum of the current node's level and the levels from its children
    return 1 + max(leftLevel, rightLevel);

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
    int s = Level(root);
    cout << "Level of the tree: " << s << endl;
    // Height of the tree is level - 1
    cout << "Height of the tree: " << s - 1 << endl;
    return 0;
}

/*

         1
        / \
       2   3
      / \   / \
     4   5 6   7
        / \
       8   9
            \
             10

In-Depth Dry Run of Level(root)

The function will drill down each path, and the result will bubble up from the leaves. The path that produces the highest number determines the final level of the tree.

---
## Step 1: The Initial Descent
main calls Level(1). To solve this, the program must first solve Level(2). To solve Level(2), it must first solve Level(4). The call stack grows with each step down.

Call Stack:
Level(4)  <-- Current Task
Level(2)
Level(1)

---
## Step 2: First Return from a Leaf (Level(4))
At Node 4: Level(4) calls Level(NULL) for its left and right children. Both return 0.
Calculation: 1 + max(0, 0) = 1.
Action: Level(4) returns 1 to its caller, Level(2).

Call Stack: Level(4) is popped.
Level(2)  <-- Return here with value 1
Level(1)

---
## Step 3: Continue Descent (Level(5) -> Level(8))
At Node 2: Level(2) has the result from its left (1). It now calls its right child, Level(5).
At Node 5: To solve Level(5), it must first solve its left child, Level(8).

Call Stack:
Level(8)  <-- Current Task
Level(5)
Level(2)
Level(1)

At Node 8: Level(8) is a leaf. It calculates 1 + max(0, 0) and returns 1 to Level(5).

---
## Step 4: The Deepest Path (Level(9) -> Level(10))
At Node 5: Level(5) has the result from its left (1). It now calls its right child, Level(9).
At Node 9: To solve Level(9), it first calls Level(left), which is NULL and returns 0. Then it must solve Level(right), which is Level(10).

Call Stack: The stack is now at its deepest point.
Level(10) <-- Current Task
Level(9)
Level(5)
Level(2)
Level(1)

At Node 10: Level(10) is a leaf. It calculates 1 + max(0, 0) and returns 1 to Level(9).

---
## Step 5: The Results Bubble Up
Now that the deepest point has been reached, the return values will travel back up the chain, getting larger as they go.

1. Return to Level(9):
   Level(9) received 0 (from left) and 1 (from right).
   Calculation: 1 + max(0, 1) = 2.
   Action: Level(9) returns 2 to Level(5).

2. Return to Level(5):
   Level(5) received 1 (from left) and 2 (from right).
   Calculation: 1 + max(1, 2) = 3.
   Action: Level(5) returns 3 to Level(2).

3. Return to Level(2):
   Level(2) received 1 (from left) and 3 (from right).
   Calculation: 1 + max(1, 3) = 4.
   Action: Level(2) returns 4 to Level(1).

---
## Step 6: Processing the Right Subtree
At Node 1: Level(1) now has the complete result from its entire left subtree (4). It now proceeds to solve the right subtree by calling Level(3).

Call Stack:
Level(3)  <-- Current Task
Level(1)

At Node 3: This process is simpler. Level(3) calls Level(6) (which returns 1) and Level(7) (which also returns 1).
Calculation: 1 + max(1, 1) = 2.
Action: Level(3) returns 2 to Level(1).

---
## Step 7: The Final Calculation at the Root
At Node 1: The original Level(1) call now has everything.
It received 4 from its left subtree (Level(2)).
It received 2 from its right subtree (Level(3)).
Final Calculation: 1 + max(4, 2) = 5.
Action: Level(1) returns 5 to the main function.

The call stack is now empty, and the final answer is 5.
*/