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
    TreeNode *construct(vector<int> &nums, int s, int e)
    {
        if (s > e)
        {
            return nullptr;
        }
        int mid = s + (e - s) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = construct(nums, s, mid - 1);
        root->right = construct(nums, mid + 1, e);
        return root;
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return construct(nums, 0, nums.size() - 1);
    }
};

int main()
{
    vector<int> nums = {-10, -3, 0, 5, 9};
    Solution s;
    TreeNode *root = s.sortedArrayToBST(nums);
    cout << root->val;
    return 0;
}