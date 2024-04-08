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
    int dfs(TreeNode *root, int sum)
    {
        if (!root)
            return 0;
        if (root->val == sum)
            return 1 + dfs(root->left, sum - root->val) + dfs(root->right, sum - root->val);
    }

public:
    int pathSum(TreeNode *root, int sum)
    {
        if (!root)
            return 0;
        return dfs(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};


int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);
    Solution s;
    cout << s.pathSum(root, 8);
    return 0;
}