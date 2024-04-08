#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* firstError;
    TreeNode* secondError;
    TreeNode* previous;

    void inorder(TreeNode* root){
        if(root == NULL)    return;

        inorder(root->left);
        if(firstError == NULL && root->val < previous->val){
            firstError = previous;
        }
        if(firstError != NULL && root->val < previous->val){
            secondError = root;
        }
         previous = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        previous = new TreeNode(INT_MIN);
        inorder(root);
        swap(firstError->val, secondError->val);
    }
};


int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    Solution s;
    s.recoverTree(root);
    cout << root->val;
    return 0;
}