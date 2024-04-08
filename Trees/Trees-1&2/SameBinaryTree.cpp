#include <iostream>
#include <vector>
#include <stack>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL)
            return true;
        if (p != NULL && q == NULL)
            return false;
        if (p == NULL && q != NULL)
            return false;

        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);

        if(p->val == q->val && left && right) return true;
        else return false;
    }
};

int main() {
    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode *q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution s;
    bool isSame = s.isSameTree(p, q);

    cout << "The two binary trees are " << (isSame ? "the same" : "different") << endl;

    return 0;
}
