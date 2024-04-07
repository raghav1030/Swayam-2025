#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> preorder;

        if (root == NULL)
            return preorder;

        stack<TreeNode *> stack;
        stack.push(root);

        while (!stack.empty())
        {
            TreeNode *node = stack.top();
            stack.pop();
            preorder.push_back(node->val);

            if (node->right != NULL)
                stack.push(node->right);
            if (node->left != NULL)
                stack.push(node->left);
        }

        return preorder;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution s;
    vector<int> preorder = s.preorderTraversal(root);

    for (auto node : preorder)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
