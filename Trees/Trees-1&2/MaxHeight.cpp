#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(T x) : val(x), left(NULL), right(NULL) {}
};

int heightOfBinaryTree(TreeNode<int> *root)
{
    if (root == NULL) return 0;
    return max(heightOfBinaryTree(root->left), heightOfBinaryTree(root->right)) + 1;
}

int main()
{
    TreeNode<int> *root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);
    root->right->left = new TreeNode<int>(6);
    root->right->right = new TreeNode<int>(7);
    root->right->right->right = new TreeNode<int>(8);
    cout << heightOfBinaryTree(root);
    return 0;
}