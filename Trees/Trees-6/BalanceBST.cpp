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

    TreeNode *generateBalancedBST(vector<int> inorder, int low, int high)
    {

        if (low > high)
            return NULL;

        int mid = low + (high - low) / 2;

        TreeNode *newNode = new TreeNode(inorder[mid]);

        newNode->left = generateBalancedBST(inorder, low, mid - 1);
        newNode->right = generateBalancedBST(inorder, mid + 1, high);

        return newNode;
    }

    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> inorder;
        inorderTraversal(root, inorder);

        return generateBalancedBST(inorder, 0, inorder.size() - 1);
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    Solution s;
    TreeNode *ans = s.balanceBST(root);
    cout << ans->val << endl;
    return 0;
}
