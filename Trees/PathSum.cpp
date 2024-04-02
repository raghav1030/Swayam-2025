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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        targetSum -= root->val;

        if(root->left == NULL && root->right == NULL && targetSum == 0) return true;

        bool leftAns = hasPathSum(root->left, targetSum);
        bool rightAns = hasPathSum(root->right, targetSum);

        return leftAns || rightAns;
    }
};

int main() {
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    Solution s;
    bool hasPath = s.hasPathSum(root, 22);

    cout << "The tree has a path with sum " << (hasPath ? "equal to" : "not equal to") << " the target sum." << endl;

    return 0;
}
