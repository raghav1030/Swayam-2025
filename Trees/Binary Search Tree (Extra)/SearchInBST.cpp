#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
         if(root == NULL) return NULL;

        if(val == root->val) return root;

        if(val < root->val){
            return searchBST(root->left, val);

        }

        else if(val > root->val){
            return searchBST(root->right, val);

        }

        return NULL;
    }

    TreeNode* searchIterativelyInBST(TreeNode* root, int val) {
        if(root == NULL) return NULL;

        TreeNode* rootNode = root;

        while(root){
            if(!root) return NULL;

            if(root->val == val) return root;

            else if(val < root->val){
                root = root->left;
            }

            else if(val > root->val){
                root = root->right;
            }
        }

        return NULL;
    }
};

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution s;
    TreeNode* rec = s.searchBST(root, 5);
    TreeNode* it = s.searchIterativelyInBST(root, 5);
    
    if(rec == NULL){
        cout << "Element not found  -> recursively" << endl;
    }
    else{
        cout << "Element found  -> recursively" << endl;
    }   


    if(it == NULL){
        cout << "Element not found -> iteratively" << endl;
    }
    else{
        cout << "Element found  -> iteratively" << endl;
    }
    return 0;
}