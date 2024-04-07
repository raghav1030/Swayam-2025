#include <bits/stdc++.h>

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
    string convertVectorIntoString(vector<int> v)
    {
        string s = "";

        for (int i = 0; i < v.size(); i++)
        {
            s.append(to_string(v[i]) + (i != v.size() - 1 ? "->" : ""));
        }
        return s;
    }
    void solve(TreeNode *root, vector<string> &ans, vector<int> &path)
    {
        if (root == NULL)
            return;

        // s.append("->" + to_string(root->val));

        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(convertVectorIntoString(path));
        }
        else
        {
            if (root->left)
                solve(root->left, ans, path);
            if (root->right)
                solve(root->right, ans, path);
        }

        // for(char ch : s) cout << ch;
        // if(s.length() > 0)s.erase(s.size()-4);
        // if(s.length)
        path.pop_back();
        return;
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;
        // string s = "";
        vector<int> path;
        solve(root, ans, path);
        return ans;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    Solution s;
    vector<string> paths = s.binaryTreePaths(root);

    for (string path : paths)
    {
        cout << path << endl;
    }

    return 0;
}