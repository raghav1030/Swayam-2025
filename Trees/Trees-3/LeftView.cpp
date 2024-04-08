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

vector<int> printLeftView(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            root = q.front();
            q.pop();
            if (i == 0)
                ans.push_back(root->data);
            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
        }
    }
    return ans;
}

int main()
{
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(3);
    root->left->left = new BinaryTreeNode<int>(4);
    root->left->right = new BinaryTreeNode<int>(5);
    root->right->left = new BinaryTreeNode<int>(6);
    root->right->right = new BinaryTreeNode<int>(7);
    root->right->right->right = new BinaryTreeNode<int>(8);
    vector<int> ans = printLeftView(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}