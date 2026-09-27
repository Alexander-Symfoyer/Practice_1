#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void inorder(TreeNode* root, vector<int> &ans) {        //! LEFT → ROOT → RIGHT 
    
    
    if (root == nullptr) {
        return;
    }

    inorder(root->left, ans);       //* Go to the left subtree

    ans.push_back(root->val);       //* Process the current node

    inorder(root->right, ans);      //* Go to the right subtree

}

vector<int> inorder_traversal(TreeNode* root) {

    vector<int> ans;

    inorder(root, ans);

    return ans;

}