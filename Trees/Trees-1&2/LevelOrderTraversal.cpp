#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (root == nullptr)
            return result;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int levelSize = q.size();
            vector<int> currentLevel;
            for (int i = 0; i < levelSize; ++i)
            {
                TreeNode *currentNode = q.front();
                q.pop();
                currentLevel.push_back(currentNode->val);

                if (currentNode->left != NULL)
                {
                    q.push(currentNode->left);
                }
                if (currentNode->right != NULL)
                {
                    q.push(currentNode->right);
                }
            }
            result.push_back(currentLevel);
        }

        return result;
    }
};

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    vector<vector<int>> result = s.levelOrder(root);

    for (const auto &level : result)
    {
        for (int node : level)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
