#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int findPosition(vector<int> &in, int element)
    {
        for (int i = 0; i < in.size(); i++)
        {
            if (element == in[i])
                return i;
        }

        return -1;
    }

    TreeNode *solve(vector<int> &post, vector<int> &in, int postorderStart, int &postorderEnd, int inorderStart, int inorderEnd, map<int, int> hashIndex)
    {
        // int n = preorderEnd;
        if (postorderStart > postorderEnd || inorderStart > inorderEnd)
            return NULL;

        int element = post[postorderEnd--];
        TreeNode *root = new TreeNode(element);
        int pos = findPosition(in, element);
        // int pos = hashIndex[element];
        root->right = solve(post, in, postorderStart, postorderEnd, pos + 1, inorderEnd, hashIndex);
        root->left = solve(post, in, postorderStart, postorderEnd, inorderStart, pos - 1, hashIndex);

        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        int postorderEnd = n - 1;

        map<int, int> hashIndex;

        for (int i = 0; i < n; i++)
        {
            hashIndex[inorder[i]] = i;
        }

        return solve(postorder, inorder, 0, postorderEnd = n - 1, 0, n - 1, hashIndex);
    }

    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
};

int main()
{
    Solution obj;
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    TreeNode *root = obj.buildTree(inorder, postorder);
    obj.inorder(root);
    return 0;
}