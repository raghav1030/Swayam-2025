#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";

        if(root == NULL) return s;

        queue<TreeNode*> q;
        q.push(root);

    while(!q.empty()){
        TreeNode* front = q.front();
        q.pop();
        

        if(front == NULL) s.append("null,");
        else{ s.append(to_string(front->val)+",");
            q.push(front->left);
            q.push(front->right);
        }
         
    }

    return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0) return NULL;
        
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            getline(s, str, ',');
            if(str == "null")  front->left = NULL;

            else{
                TreeNode* newNode = new TreeNode(stoi(str));
                front->left = newNode;
                q.push(newNode);
            }

            getline(s, str, ',');

            if(str == "null")  front->right = NULL;

            else{
                TreeNode* newNode = new TreeNode(stoi(str));
                front->right = newNode;
                q.push(newNode);
            }
        }

        return root;
    }
};


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec codec;
    string s = codec.serialize(root);
    cout<<s<<endl;
    TreeNode* newRoot = codec.deserialize(s);
    cout<<codec.serialize(newRoot)<<endl;
    return 0;
}