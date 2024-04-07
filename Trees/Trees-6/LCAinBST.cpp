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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // if(root == NULL) return NULL;

        // if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);

        // if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);

        // else return root;

        while (root)
        {

            if (root->val < p->val && root->val < q->val)
                root = root->right;

            else if (root->val > p->val && root->val > q->val)
                root = root->left;
            else
                return root;
        }

        return NULL;
    }
};

int main()
{
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    Solution s;
    TreeNode *ans = s.lowestCommonAncestor(root, root->left, root->right);
    cout << ans->val << endl;
    return 0;
}