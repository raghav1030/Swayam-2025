#include  <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
};


int pred(TreeNode *root, int key){

    int pre = -1;

    while(root){
        if(key <= root->data ) root = root->left;

        else {
            pre = root->data;
            root = root->right;
        }

    }

    return pre;


}

int succ(TreeNode *root, int key){
int suc = -1;

    while(root){
        if(key >= root->data ) root = root->right;

        else {
            suc = root->data;
            root = root->left;
        }

    }

    return suc;
}


pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.
    if(root == NULL) return {};

    return {pred(root, key) , succ(root, key)};

}


int main() {
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(70);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(40);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(80);

    pair<int, int> ans = predecessorSuccessor(root, 65);
    cout << ans.first << " " << ans.second << endl;
    return 0;
}