#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
};

vector<int> RightViewOfBinaryTree(BinaryTreeNode<int> *root)
{

    vector<int> ans;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        // vector<int> v;
        for (int i = 0; i < size; i++)
        {
            root = q.front();
            q.pop();
            if (i == size - 1)
                ans.push_back(root->data);
            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
        }
    }
    return ans;
}
