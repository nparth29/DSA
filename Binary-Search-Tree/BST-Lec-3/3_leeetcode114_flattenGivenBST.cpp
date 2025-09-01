#include <iostream>
#include <vector>
using namespace std;

// TreeNode definition
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ------------------- Method 1: Using Preorder Traversal + Vector -------------------
class Solution1 {
public:
    void preOrder(TreeNode* root, vector<TreeNode*> & ans){
        if(root == NULL) return;
        ans.push_back(root);
        preOrder(root->left, ans);
        preOrder(root->right, ans);
    }

    vector<TreeNode*> helper(TreeNode* root){
        vector<TreeNode*> ans;
        preOrder(root, ans);
        return ans;
    }

    void flatten(TreeNode* root) {
        vector<TreeNode*> result = helper(root);
        int n = result.size();
        for(int i = 0; i < n-1; i++){
            result[i]->right = result[i+1];
            result[i]->left = NULL;
        }
    }
};

// ------------------- Method 2: Using Recursion -------------------
class Solution2 {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;

        TreeNode* l = root->left;
        TreeNode* r = root->right;

        root->left = NULL;
        root->right = NULL;

        flatten(l);
        flatten(r);

        root->right = l;

        TreeNode* temp = root;
        while(temp->right != NULL) temp = temp->right;

        temp->right = r;
    }
};

// ------------------- Method 3: Using Morris Traversal Concept -------------------
class Solution3 {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr->left != NULL){
                TreeNode* r = curr->right;
                curr->right = curr->left;

                TreeNode* pred = curr->left;
                while(pred->right != NULL) pred = pred->right;

                pred->right = r;
                curr = curr->left;
            }
            else curr = curr->right;
        }

        TreeNode* temp = root;
        while(temp != NULL){
            temp->left = NULL;
            temp = temp->right;
        }
    }
};

// ------------------- Helper Functions -------------------
TreeNode* buildSampleTree() {
    // Example Tree:
    //      1
    //     / \
    //    2   5
    //   / \   \
    //  3   4   6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    root->left->right->right = new TreeNode(7);
    return root;
}

void printFlattened(TreeNode* root) {
    TreeNode* curr = root;
    while(curr != NULL){
        cout << curr->val << " ";
        curr = curr->right;
    }
    cout << endl;
}

// ------------------- Main Function -------------------
int main() {
    // Method 1
    TreeNode* root1 = buildSampleTree();
    Solution1 s1;
    s1.flatten(root1);
    cout << "Flattened Tree (Method 1): ";
    printFlattened(root1);

    // Method 2
    TreeNode* root2 = buildSampleTree();
    Solution2 s2;
    s2.flatten(root2);
    cout << "Flattened Tree (Method 2): ";
    printFlattened(root2);

    // Method 3
    TreeNode* root3 = buildSampleTree();
    Solution3 s3;
    s3.flatten(root3);
    cout << "Flattened Tree (Method 3): ";
    printFlattened(root3);

    return 0;
}
