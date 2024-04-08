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

private:
    TreeNode *findSuccessorFromLeft(TreeNode *root, int val)
    {
        TreeNode *succ = root;

        while (root)
        {
            if (root == NULL)
                return NULL;

            if (root->val <= val)
                root = root->right;

            else
            {
                succ = root;
                root = root->left;
            }
        }

        return succ;
    }

    TreeNode *findMaxFromLeft(TreeNode *root)
    {
        if (root == NULL)
            return NULL;

        if (root->right == NULL)
            return root;

        return findMaxFromLeft(root->right);

        // return maxi;
    }

    TreeNode *findMinFromRight(TreeNode *root)
    {
        if (root == NULL)
            return NULL;

        if (root->left == NULL)
            return root;

        return findMaxFromLeft(root->left);

        // return maxi;
    }

public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == NULL)
            return NULL;

        if (root->val == key)
        {

            if (!root->left && !root->right)
            {
                // TreeNode* temp = root;
                delete root;
                return NULL;
            }

            if (root->left && !root->right)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }

            if (!root->left && root->right)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }

            if (root->left && root->right)
            {
                TreeNode *temp = findMaxFromLeft(root->left);
                root->val = temp->val;
                root->left = deleteNode(root->left, temp->val);
            }
        }

        else if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }

        else if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }

        return root;
    }
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    Solution s;
    s.deleteNode(root, 3);
    return 0;
}