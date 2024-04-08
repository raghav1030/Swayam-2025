#include <iostream>
#include <vector>
#include <cstdlib>

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
    void solve(TreeNode *root, vector<int> &arr, int &count, int targetSum)
    {
        if (root == NULL)
            return;

        arr.push_back(root->val);

        solve(root->left, arr, count, targetSum);
        solve(root->right, arr, count, targetSum);

        long long int sum = 0;
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            sum += arr[i];

            if (sum == targetSum)
                count++;
        }

        arr.pop_back();
    }

    int pathSum(TreeNode *root, int targetSum)
    {
        if (root == NULL)
            return 0;

        vector<int> arr;
        int count = 0;

        solve(root, arr, count, targetSum);
        return count;
    }
};

int main()
{
    Solution solution;

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;
    int count = solution.pathSum(root, targetSum);

    cout << "Number of paths that sum to " << targetSum << ": " << count << endl;

    return 0;
}
