#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void convertBSTIntoSortedDLL(BinaryTreeNode<int>* root, BinaryTreeNode<int>* &head){
    if(root == NULL) return ;

    convertBSTIntoSortedDLL(root->right, head);

    root->right = head;
    if(head != NULL) head->left = root;

    head = root;

    convertBSTIntoSortedDLL(root->left, head);
}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
    BinaryTreeNode<int>* head = NULL;
    convertBSTIntoSortedDLL(root, head);

    return head;
}

void printDLL(BinaryTreeNode<int>* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->right;
    }
}

int main() {
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(10);
    root->left = new BinaryTreeNode<int>(5);
    root->right = new BinaryTreeNode<int>(20);
    root->left->left = new BinaryTreeNode<int>(3);
    root->left->right = new BinaryTreeNode<int>(8);
    root->right->left = new BinaryTreeNode<int>(15);
    root->right->right = new BinaryTreeNode<int>(30);

    BinaryTreeNode<int>* head = BTtoDLL(root);
    printDLL(head);
    return 0;
}