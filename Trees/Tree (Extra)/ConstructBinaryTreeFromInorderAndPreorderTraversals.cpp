#include <iostream>
#include <vector>
#include <map>

using namespace std;


class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};


class Solution {
public:

    int findPosition (vector<int> &in, int element){
        for(int i = 0; i < in.size(); i++){
            if(element == in[i]) return i;
        }

        return -1;
    }
    TreeNode* solve(vector<int>& pre, vector<int>& in, int &preorderStart, int preorderEnd, int inorderStart, int inorderEnd, map<int,int> hashIndex){
        // int n = preorderEnd;
        if(preorderStart > preorderEnd || inorderStart > inorderEnd) return NULL;

        int element = pre[preorderStart++];
        TreeNode* root = new TreeNode(element);
        // int pos = findPosition(in, element); 
        int pos = hashIndex[element];
        root->left = solve(pre, in, preorderStart, preorderEnd, inorderStart, pos-1, hashIndex);
        root->right = solve(pre, in, preorderStart, preorderEnd, pos+1, inorderEnd, hashIndex);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderStart = 0;
        int n = inorder.size();

        map<int, int> hashIndex;

        for(int i = 0; i < n; i++){
            hashIndex[inorder[i]] = i;
        }

        return solve(preorder, inorder, preorderStart, n-1, 0, n-1, hashIndex);
    }

    void inorder(TreeNode* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

};





int main(){
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};

    Solution s;
    TreeNode* root = s.buildTree(preorder, inorder);
    s.inorder(root);
    return 0;
}

