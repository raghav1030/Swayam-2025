#include <bits/stdc++.h> 
using namespace std;

template <typename T>
class BinaryTreeNode {
    public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};


 bool checkBST(BinaryTreeNode<int>* root, int mini, int maxi){
        if(root == NULL) return true;

        // bool left = true;
        // bool right = true;
        
        // cout << root->data << " " << maxi << endl; 
        if(root->data < maxi && root->data > mini){
            // if(root->left) left = checkBST(root->left, mini, root->val);
            // if(root->right) right = checkBST(root->right, root->val, maxi);

            //  return left && right;

            if(root->left && root->right){
                int left = checkBST(root->left, mini, root->data);
                int right = checkBST(root->right, root->data, maxi);
                return left && right;
            }

            else if(!root->left && root->right){
                return  checkBST(root->right, root->data, maxi);
            }
            
            else if(root->left && !root->right){
                return  checkBST(root->left, mini, root->data);
            }
            else return true;

        }

        else return false;
        
    }
bool validateBST(BinaryTreeNode<int>* root) 
{
    // Write your code here
    return checkBST(root, INT_MIN, INT_MAX);
}


BinaryTreeNode<int>* takeInputLevelWise() {
    int data;
    cin >> data;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(data);

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0) {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int leftData;
        cin >> leftData;
        if (leftData != -1) {
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftData);
            front->left = child;
            pendingNodes.push(child);
        }

        int rightData;
        cin >> rightData;
        if (rightData != -1) {
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightData);
            front->right = child;
            pendingNodes.push(child);
        }
    }

    return root;
}