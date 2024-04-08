#include <iostream>
#include <vector>
#include <stack>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int height(TreeNode* root){
        if (root == NULL) return 0;

        int l = height(root->left);
        int r = height(root->right);

        return max(l, r) + 1;
    }

    pair<bool, int> isBalancedOptimized(TreeNode* root){
        if(root == NULL) return {true,0};

        pair<bool,int> left = isBalancedOptimized(root->left);
        pair<bool,int> right = isBalancedOptimized(root->right);

        pair<int,int> ans;

        if(left.first && right.first && abs(left.second-right.second) <= 1) {
            ans.first = true;
        }
        else {
            ans.first = false;
        }

        ans.second = max(left.second, right.second) +1;

        return ans;
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;

        return isBalancedOptimized(root).first;

        // int l = height(root->left);
        // int r = height(root->right);

        // bool checkLeft = isBalanced(root->left);
        // bool checkRight = isBalanced(root->right);

       

        // return abs(l-r) <= 1 && checkLeft && checkRight;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution s;
    bool isBalanced = s.isBalanced(root);

    cout << "The binary tree is " << (isBalanced ? "balanced" : "not balanced") << endl;

    return 0;
}
