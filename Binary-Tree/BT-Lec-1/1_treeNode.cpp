#include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val){
        this->val = val;
        this->left = NULL; 
        this->right = NULL; 
    }
};

void displayTree(Node* node){
    if (node == NULL) {
        return;
    }
    cout << node->val << " ";
    displayTree(node->left);
    displayTree(node->right);
}

int main() {
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
    displayTree(root);
    cout << endl;
    return 0;
}


/*
Visual Walkthrough of displayTree(root)
Here is the path the program takes, step-by-step.
Initial State: The main function calls displayTree on the root node.

Tree:

      1  <-- We are here
     / \
    2   3
   / \ / \
  4  5 6  7
Action: displayTree(1) is called.
Call Stack: [ displayTree(1) ]

----------------------------------------------------

Step 1: Process Node 1

Action: The function prints the node's value (1) and then calls displayTree on its left child (Node 2).
Output: 1 
Call Stack: A new call is added on top.

displayTree(2)  <-- Current task
displayTree(1)

----------------------------------------------------

Step 2: Process Node 2

Tree:

      1
     / \
    2   3  <-- We are here
   / \ / \
  4  5 6  7
Action: The function prints the node's value (2) and calls displayTree on its left child (Node 4).
Output: 1 2 
Call Stack:

displayTree(4)  <-- Current task
displayTree(2)
displayTree(1)

----------------------------------------------------

Step 3: Process Node 4 (A Leaf)

Tree:

      1
     / \
    2   3
   / \ / \
  4   5 6  7  <-- We are here
Action: The function prints the node's value (4). It tries to go left, but finds NULL. It tries to go right, but finds NULL. The function for Node 4 is now done.
Output: 1 2 4 
Call Stack: The displayTree(4) task is finished and gets popped off the stack.

displayTree(2)  <-- Return here
displayTree(1)

----------------------------------------------------

Step 4: Return to Node 2

Action: We are back at the displayTree(2) call. The left side is complete. Now, we follow the next instruction: call displayTree on the right child (Node 5).
Output: 1 2 4 
Call Stack:

displayTree(5)  <-- Current task
displayTree(2)
displayTree(1)

----------------------------------------------------

Step 5: Process Node 5 (A Leaf)

Tree:

      1
     / \
    2   3
   / \ / \
  4   5 6  7  <-- We are here
Action: The function prints 5. Finding NULL on its left and right, the function for Node 5 is done.
Output: 1 2 4 5 
Call Stack: displayTree(5) is popped off.

displayTree(2)  <-- Return here
displayTree(1)

----------------------------------------------------

Step 6: Return to Node 2... and then Node 1

Action: We are back at displayTree(2). Its left and right children have been fully explored. This function is now done. It gets popped off the stack.
Call Stack:

displayTree(1)  <-- Return here
We are now back at the original displayTree(1) call. Its entire left side (2, 4, 5) is complete. The next instruction is to go right.

----------------------------------------------------

Step 7: Process Node 3

Tree:

      1
     / \
    2   3  <-- We are here
   / \ / \
  4  5 6  7
Action: displayTree is called on Node 3. The function prints 3 and calls displayTree on its left child (Node 6).
Output: 1 2 4 5 3 
Call Stack:

displayTree(6)  <-- Current task
displayTree(3)
displayTree(1)

----------------------------------------------------

Step 8 & 9: Process Node 6, then Node 7
The process repeats exactly as it did for the left side of the tree.

1. Node 6 is processed. Output becomes ... 3 6. The call for Node 6 finishes.
2. We return to Node 3. Its left side is done. We go right, calling displayTree on Node 7.
3. Node 7 is processed. Output becomes ... 6 7. The call for Node 7 finishes.

----------------------------------------------------

Final Step: Completion

We return to Node 3. Its left and right children are done. The displayTree(3) call is popped.
We return to Node 1. Its left and right children are done. The displayTree(1) call is popped.
The call stack is now empty. The entire traversal is finished.

Final Output: "1 2 4 5 3 6 7"
*/


