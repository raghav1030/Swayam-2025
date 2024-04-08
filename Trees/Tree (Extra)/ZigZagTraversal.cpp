#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;
        while(!q.empty()){

            int size = q.size();
            vector<int> inorder(size);

            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                int index = leftToRight ? i : size-1-i;

                // inorder.push_back(node->val);
                inorder[index] = node->val;
                // if(leftToRight){
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                // }

                // else{
                //     if(node->left)q.push(node->left);
                //     if(node->right)q.push(node->right);
                // }
            }

                    
            if(leftToRight) leftToRight = false;
             
            else leftToRight = true; 

            ans.push_back(inorder);

        }

        return ans;
    }
};

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    vector<vector<int>> ans = s.zigzagLevelOrder(root);

    for (auto level : ans) {
        for (auto node : level) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
