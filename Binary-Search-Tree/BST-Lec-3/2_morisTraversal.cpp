#include<iostream>
using namespace std;
#include<vector>

// Your exact Node class definition
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

// Your exact inOrder function for Morris Traversal
vector<int> inOrder(Node* root){
    vector<int> ans;
    Node *curr = root;
    while(curr != NULL){
        // find the predecessor of curr 
        if(curr->left != NULL){
            Node* pred = curr->left;
            while(pred->right != NULL && pred->right != curr){
                pred = pred->right;
            }
            if(pred->right == NULL){
                pred->right = curr; // linking the predecessor to curr
                curr = curr->left; // move to left subtree
            }
            else{
                // pred->right == curr : unlinking the predecessor from curr
                pred->right = NULL;
                // visit the curr node 
                ans.push_back(curr->val);
                curr = curr->right; // move to right subtree
            }
        }
        else{
            // visit the current node 
            ans.push_back(curr->val);
            curr = curr->right; // move to right subtree
        }
    }
    return ans;
}

// Main function to test your code
int main() {
    // Build a sample binary tree:
    //      4
    //     / \
    //    2   6
    //   / \ / 
    //  1  3 5  
    Node* root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right = new Node(6);
    root->right->left = new Node(5);

    cout << "Performing Morris In-order Traversal..." << endl;

    // Call your inOrder function
    vector<int> result = inOrder(root);

    cout << "Result: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
