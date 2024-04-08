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

int solve(BinaryTreeNode<int>* root, int k, int &i){
    if(root == NULL) {
        return -1;
    }

    int left = solve(root->left, k, i);
    if(left != -1) return left;

    i++;
    if(i==k) return root->data;


    return solve(root->right, k, i);
    // solve(root->left, k, i);


}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Write your code here.
    int i = 0;
    return solve(root, k , i);
}

BinaryTreeNode<int>* takeInputLevelWise() {
    int data;
    cin >> data;

    if(data == -1) {
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(data);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while(!q.empty()) {
        BinaryTreeNode<int>* front = q.front();
        q.pop();

        cin >> data;
        if(data != -1) {
            BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(data);
            front -> left = leftChild;
            q.push(leftChild);
        }

        cin >> data;
        if(data != -1) {
            BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(data);
            front -> right = rightChild;
            q.push(rightChild);
        }
    }

    return root;
}