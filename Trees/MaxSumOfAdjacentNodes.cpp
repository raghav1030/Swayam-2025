#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

class Solution{
  public:
  
    pair<int, int> solve(Node* root){
        if(root == NULL) return {0,0};
        
        pair<int,int> leftAns = solve(root->left);
        pair<int,int> rightAns = solve(root->right);
        
        return {root->data + leftAns.second + rightAns.second, max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second) };
    }
    
    
    int getMaxSum(Node *root) 
    {
        // Add your code here
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};

int main(){
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
    
    Solution solution;
    cout<<solution.getMaxSum(root);
    return 0;
}