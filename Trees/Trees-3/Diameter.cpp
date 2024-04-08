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
private:
    // int height(TreeNode* root){
    //     if(root == NULL) return 0;

    //     int l = height(root->left);
    //     int r = height(root->right);
    //     return max(l , r) + 1; 
        
    // }

    pair<int, int> diameterOptimized(TreeNode* root){
        if(root == NULL) return {0,0};

        pair<int, int> left = diameterOptimized(root->left);
        pair<int, int> right = diameterOptimized(root->right);
        int option1 = left.first;
        int option2 = right.first;
        int option3 =left.second + right.second ;

        return {max(option1, max(option2, option3)), max(left.second, right.second) + 1};
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        return diameterOptimized(root).first;
        // if(root == NULL) return 0;

        // int option1 = diameterOfBinaryTree(root->left);
        // int option2 = diameterOfBinaryTree(root->right);
        // int option3 = height(root->left) + height(root->right) ;
        // return max(option1 , max(option2, option3));
    }
};

int main() {
    // Create a tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution s;
    int diameter = s.diameterOfBinaryTree(root);

    cout << "The diameter of the binary tree is: " << diameter << endl;

    return 0;
}
