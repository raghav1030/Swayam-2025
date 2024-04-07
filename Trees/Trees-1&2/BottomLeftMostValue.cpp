#include <bits/stdc++.h>
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
    int findBottomLeftValue(TreeNode* root) {
         if(root == NULL) return 0;
       
       queue<TreeNode*> q;
       q.push(root);
       
       int leftMostValue = -1;

       
       while(!q.empty()){
           int size = q.size();
  
           for(int i = 0; i < size; i++){
               TreeNode* front = q.front();
               q.pop();
               
               if(i==0) leftMostValue = front->val;
               
               if(front->left) q.push(front->left);
               if(front->right) q.push(front->right);
               
           }
       }

       return leftMostValue;
    }
};



int main() {
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Solution s;
    int leftMostValue = s.findBottomLeftValue(root);

    cout << "The left most value of the tree is: " << leftMostValue << endl;

    return 0;
}