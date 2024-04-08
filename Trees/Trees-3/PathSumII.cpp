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
    void pathSum(TreeNode *root, int targetSum, vector<int> &v, vector<vector<int>> &ans)
    {
        if (root == NULL)
            return;

        v.push_back(root->val);

        if (root->left == NULL && root->right == NULL && root->val == targetSum)
            ans.push_back(v);

        pathSum(root->left, targetSum - root->val, v, ans);
        pathSum(root->right, targetSum - root->val, v, ans);

        v.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> ans;
        vector<int> v;
        pathSum(root, targetSum, v, ans);
        return ans;
    }
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);
    Solution s;
    vector<vector<int>> ans = s.pathSum(root, 22);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}