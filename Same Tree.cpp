/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // straight-forward implementation
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(!p && !q)
            return true;
        if((!p && q) || (p && !q)) 
            return false;
        if(p->val != q->val)
            return false;
        if(isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
            return true;
    }
};