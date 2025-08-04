// Binary Tree Size Calculation
#include <iostream>
#include <limits> 
#include<algorithm> 

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

int maximumVal(Node* node) {
    if (node == NULL) {
        return std::numeric_limits<int>::min();  // Base case: if the node is NULL, return the smallest integer
    }
    // Recursive case: find the maximum value in the left and right subtrees
    // and compare it with the current node's value
    return max(node->val, max(maximumVal(node->left), maximumVal(node->right)));

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
    int s = maximumVal(root);
    cout << "Maximum Node value: " << s << endl;
    
    return 0;
}
