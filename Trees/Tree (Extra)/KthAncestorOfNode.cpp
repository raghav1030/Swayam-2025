#include <iostream>
#include <climits>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *solve(Node *root, int &k, int node)
{

    if (root == NULL)
        return NULL;

    if (root->data == node)
        return root;

    Node *left = solve(root->left, k, node);
    Node *right = solve(root->right, k, node);

    // if(!left && !right) return NULL;

    if (!left && !right)
        return NULL;

    if (left && !right)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return left;
    }
    if (!left && right)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return right;
    }
}

int kthAncestor(Node *root, int k, int node)
{
    // Code here
    Node *ans = solve(root, k, node);

    if (ans == NULL || ans->data == node)
        return -1;

    else
        return ans->data;
}

int main()
{
    Node *root = new Node();
    root->data = 1;
    root->left = new Node();
    root->left->data = 2;
    root->right = new Node();
    root->right->data = 3;
    root->left->left = new Node();
    root->left->left->data = 4;
    root->left->right = new Node();
    root->left->right->data = 5;
    root->right->left = new Node();
    root->right->left->data = 6;
    root->right->right = new Node();
    root->right->right->data = 7;
    root->left->left->left = new Node();
    root->left->left->left->data = 8;
    root->left->left->right = new Node();
    root->left->left->right->data = 9;
    root->left->right->left = new Node();
    root->left->right->left->data = 10;
    root->left->right->right = new Node();
    root->left->right->right->data = 11;
    root->right->left->left = new Node();
    root->right->left->left->data = 12;
    root->right->left->right = new Node();
    root->right->left->right->data = 13;
    root->right->right->left = new Node();
    root->right->right->left->data = 14;
    root->right->right->right = new Node();
    root->right->right->right->data = 15;
    cout << kthAncestor(root, 2, 4);
    return 0;
}