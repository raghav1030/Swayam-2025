#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
};


void inorderTraversal(TreeNode* root,  vector<int> &inorder){
    if(root ==  NULL) return ;

    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}

vector<int> mergeTwoSortedArrays(vector<int> a, vector<int> b){
    vector<int> ans;

    int i = 0;
    int j = 0;

    while(i< a.size() && j < b.size()){
        if(a[i] <b[j]){
            ans.push_back(a[i]);
            i++;
        }

        else{
            ans.push_back(b[j]);
            j++;
        }
    }

    while(i < a.size()){
         ans.push_back(a[i]);
            i++;
    }

    while(j < b.size()){

  ans.push_back(b[j]);
            j++;
    }

    return ans;
}

TreeNode* constructBSTFromInorderTraversal(vector<int> finalArr, int s, int e){
    if(s>e) return NULL;

    int mid  = s + (e-s)/2;

    TreeNode* root = new TreeNode(finalArr[mid]);

    root->left = constructBSTFromInorderTraversal(finalArr, s, mid-1);
    root->left = constructBSTFromInorderTraversal(finalArr, mid+1, e);


    return root;
}

void convertBSTIntoSortedDLL(TreeNode* root, TreeNode* &head){
    if(root == NULL) return;

    convertBSTIntoSortedDLL(root->left, head);

    root->right = head;
    
    if(head != NULL) head->left = root;

    head = root;

    convertBSTIntoSortedDLL(root->left, head);
}   


TreeNode* mergeSortedDLL(TreeNode* head1 , TreeNode* head2){
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;

    TreeNode* head = NULL;
    TreeNode* tail = NULL;

    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            if(head == NULL){
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else{
                tail -> right = head1;
                head1->left = tail;
                tail = tail->right;
                head1 = head1->right;
            }
        }
        else{
            if(head == NULL){
                head = head2;
                tail = head2;
                head1 = head2->right;
            }
            else{
                tail -> right = head2;
                head2->left = tail;
                tail = tail->right;
                head2 = head2->right;
            }
        }
    }

    while(head1 != NULL){
        tail -> right = head1;
        head1->left = tail;
        tail = tail->right;
        head1 = head1->right; 
    }

    while(head2 != NULL){
        tail -> right = head2;
        head2->left = tail;
        tail = tail->right;
        head1 = head2->right; 
    }

    return head;


}

int countNodes(TreeNode* head){
    if(head == NULL) return 0;

    TreeNode* temp = head;

    int count = 0;

    while(temp != NULL){
        count++;
        temp = temp->right;
    }
    return count;
}

TreeNode* constructBSTFromDLL(TreeNode* &head, int n){
    if(n <= 0 || head == NULL) return NULL;


    TreeNode* left = constructBSTFromDLL(head, n/2);
    TreeNode* root = head;
    root->left = left;

    // if(left) left->right = root;
    head = root;

    TreeNode* right = constructBSTFromDLL(head, n - n/2 - 1);

    return root;

}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    vector<int> inorder1, inorder2;

    inorderTraversal(root1, inorder1);
    inorderTraversal(root2, inorder2);

    vector<int> finalArr = mergeTwoSortedArrays(inorder1, inorder2);
    return finalArr;

    // return constructBSTFromInorderTraversal(finalArr, 0, finalArr.size()-1);

/**********************************************************************************************/
    // TreeNode* head1 = NULL;
    // TreeNode* head2 = NULL;

    // convertBSTIntoSortedDLL(root1, head1);
    // convertBSTIntoSortedDLL(root2, head2);

    // head1->left = NULL;
    // head2->left = NULL;


    // TreeNode* newHead = mergeSortedDLL(head1, head2);

    // return constructBSTFromDLL(newHead, countNodes(newHead));

}


int main()
{
    TreeNode* root1 = new TreeNode(10);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(20);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(8);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(30);

    TreeNode* root2 = new TreeNode(12);
    root2->left = new TreeNode(6);
    root2->right = new TreeNode(25);
    root2->left->left = new TreeNode(2);
    root2->left->right = new TreeNode(9);
    root2->right->left = new TreeNode(18);
    root2->right->right = new TreeNode(35);

    vector<int> ans = mergeBST(root1, root2);

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}