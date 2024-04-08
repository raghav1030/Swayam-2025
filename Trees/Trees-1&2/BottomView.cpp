#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class TreeSolution {
 public:
    vector<int> getBottomView(TreeNode *root) {
        map<int,int> m; 
        queue<pair<TreeNode*,int>> q;
        vector<int> ans;
        if(root==NULL) return ans;
        q.push({root,0});
        while(!q.empty())
        {
            auto t=q.front();
            q.pop();
            root=t.first;
            int l=t.second;
            m[l]=(root->val);
            if(root->left)
                q.push({root->left,l-1}); 
            if(root->right)
                q.push({root->right,l+1});
        }
        
        for(auto i:m)
        {
            ans.push_back(i.second);
        }
           
        return ans;
    }
};


int main()
{
    TreeNode *root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->right = new TreeNode(22);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(25);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(14);
    TreeSolution s;
    vector<int> ans = s.getBottomView(root);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    return 0;
}