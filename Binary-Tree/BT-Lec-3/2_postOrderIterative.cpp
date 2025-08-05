#include<iostream>
using namespace std;
#include<stack>
#include<algorithm>
#include<vector>

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

vector<int> postOrderIterative(Node* root){
    stack<Node *> s;
    vector<int> result;
    if(root == NULL) return result; // If the tree is empty, return an empty
    s.push(root);

    while(s.size() > 0){
        Node* temp = s.top();
        s.pop();
        result.push_back(temp->val); // Process the current node

        if(temp->left != NULL) s.push(temp->left);
        if(temp->right!= NULL) s.push(temp->right);
        

    }
    // Reverse the result to get post-order
    reverse(result.begin(), result.end());
    return result;
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
    postOrderIterative(root);
    for(int val : postOrderIterative(root)){
        cout << val << " ";
    }
    cout << endl;

}
