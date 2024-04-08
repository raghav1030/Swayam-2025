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
    void inorderTraversal(TreeNode *root, vector<int> &inorder)
    {
        if (!root)
            return;

        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }

    bool twoSumExistInVector(vector<int> inorder, int k)
    {
        int i = 0;
        int j = inorder.size() - 1;

        int sum = 0;

        while (i < j)
        {
            sum = inorder[i] + inorder[j];

            if (sum == k)
                return true;

            else if (sum > k)
                j--;

            else if (sum < k)
                i++;
        }

        return false;
    }

    bool findTarget(TreeNode *root, int k)
    {
        vector<int> inorder;
        inorderTraversal(root, inorder);

        return twoSumExistInVector(inorder, k);
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
    cout << s.findTarget(root, 9) << endl;
    return 0;
}
