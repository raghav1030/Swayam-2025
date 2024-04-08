#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == NULL) return ans;

        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int,int>>> q;

        q.push({root, {0,0}});

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            TreeNode* node = p.first;
            int horizontalDistance = p.second.first;
            int level = p.second.second;

            nodes[horizontalDistance][level].insert(node->val);

            if(node->left) q.push({node->left, {horizontalDistance-1, level+1}});
            if(node->right) q.push({node->right, {horizontalDistance+1, level+1}});
        }

        for(auto i : nodes){
            vector<int> temp;
            for(auto j: i.second){
                temp.insert(temp.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(temp);
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
    vector<vector<int>> ans = s.verticalTraversal(root);

    for (auto level : ans) {
        for (auto node : level) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
