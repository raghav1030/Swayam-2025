#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
private:
    vector<int> inorder(Node *root, vector<int> &ans)
    {
        if (root == NULL)
            return ans;
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
        return ans;
    }

    bool BinarySearch(vector<int> &v, int target)
    {
        int start = 0;
        int end = v.size() - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (v[mid] == target)
                return true;
            else if (v[mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return false;
    }

public:
    // Function to find the nodes that are common in both BST.
    vector<int> findCommon(Node *root1, Node *root2)
    {
        vector<int> v, u, ans;
        inorder(root1, v);
        inorder(root2, u);
        for (auto i : u)
        {
            if (BinarySearch(v, i))
                ans.push_back(i);
        }
        return ans;
    }
};
