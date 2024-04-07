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
    TreeNode *constructBST(vector<int> &preorder, int &i, int mini, int maxi)
    {
        if (i >= preorder.size())
            return NULL;

        // if (preorder[i] < mini || preorder[i] > maxi)
        // {
        //     return NULL;
        // }
        if (preorder[i] > maxi)
        {
            return NULL;
        }

        TreeNode *newNode = new TreeNode(preorder[i++]);

        newNode->left = constructBST(preorder, i, mini, newNode->val);
        newNode->right = constructBST(preorder, i, newNode->val, maxi);

        return newNode;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        // TreeNode* root = new TreeNode(preorder[0]);
        int mini = INT_MIN;
        int maxi = INT_MAX;
        int i = 0;
        return constructBST(preorder, i, mini, maxi);
        // return root;
    }
};

int main()
{
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    Solution s;
    TreeNode *root = s.bstFromPreorder(preorder);
    cout << root->val << endl;
    return 0;
}
