#include<iostream>
using namespace std;
#include<stack>
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

vector<int> inOrderIterative(Node* root){
    stack<Node *> s;
    Node *node = root;
    vector<int> result;
    if(root == NULL) return result; // If the tree is empty, return an empty

    while(s.size() >0 || node != NULL ){
        if(node){
            s.push(node);
            node = node->left;
        }
        else{
            Node *temp = s.top();
            s.pop();
            result.push_back(temp->val);
            node = temp->right;
        }
    }
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

    // Call the function ONCE and store the result
    vector<int> inorderResult = inOrderIterative(root);

    // Loop over the stored result
    for (int val : inorderResult) {
        cout << val << " ";
    }
    cout << endl;
    // Expected Output: 4 2 5 1 6 3 7


}
