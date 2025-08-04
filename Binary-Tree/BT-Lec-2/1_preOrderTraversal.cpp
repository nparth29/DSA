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

void preOrder(Node* node){
    if (node == NULL) {
        return;
    }
    cout << node->val << " "; // pre
    preOrder(node->left);  //call 1
    preOrder(node->right);  // call 2
}

void inOrder(Node* node){
    if (node == NULL) {
        return;
    }
    inOrder(node->left);  // call 1
    cout << node->val << " ";  //  in
    inOrder(node->right);  // call 2
}
void postOrder(Node* node){
    if (node == NULL) {
        return;
    }
    postOrder(node->left);  // call 1
    postOrder(node->right);  // call 2
    cout << node->val << " ";  // post
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
    cout << "Pre-Order Traversal: ";
    preOrder(root);
    cout << endl;
    cout << "In-Order Traversal: ";
    inOrder(root);
    cout << endl;
    cout << "Post-Order Traversal: ";
    postOrder(root);
    cout << endl;
    return 0;
}
