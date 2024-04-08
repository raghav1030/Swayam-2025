#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    void preorderTraversal(TreeNode *root, vector<int> &preorder)
    {
        if (root == NULL)
            return;

        preorder.push_back(root->val);
        preorderTraversal(root->left, preorder);
        preorderTraversal(root->right, preorder);
    }

    void generateLLfromVector(TreeNode *root, vector<int> preorder)
    {
        TreeNode *newRoot = root;
        newRoot->val = preorder[0];

        for (int i = 1; i < preorder.size(); i++)
        {
            cout << preorder[i] << " ";
            TreeNode *temp = new TreeNode(preorder[i]);
            // newRoot = preorder[i];
            newRoot->left = NULL;
            newRoot->right = temp;
            newRoot = newRoot->right;
        }

        newRoot->left = NULL;
        newRoot->right = NULL;
    }

    void flatten(TreeNode *root)
    {
        if (root == NULL)
            return;
        vector<int> preorder;
        preorderTraversal(root, preorder);

        // for(int i : preorder) cout << i << " ";

        generateLLfromVector(root, preorder);
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    Solution s;
    s.flatten(root);

    while (root)
    {
        cout << root->val << " ";
        root = root->right;
    }

    return 0;
}