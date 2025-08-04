// Binary Tree Size Calculation
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

int sizeOfBinaryTree(Node* node) {
    if (node == NULL) {
        return 0; // Base case: if the node is NULL, return 0
    }
    // Recursive case: count the current node and the nodes in its left and right subtrees
    return 1 + sizeOfBinaryTree(node->left) + sizeOfBinaryTree(node->right);
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
    int s = sizeOfBinaryTree(root);
    cout << "Number of Nodes is : " << s << endl;
    
    return 0;
}
