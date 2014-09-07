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
    // post-order traverse & the usage of -1
    bool isBalanced(TreeNode *root) {
        return getDepth(root) != -1;
    }
    int getDepth(TreeNode *root){
        if(NULL == root)
            return 0;
        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);
        if(leftDepth == -1 || rightDepth == -1 || abs(leftDepth - rightDepth) > 1)
            return -1;
        else
            return max(leftDepth, rightDepth) + 1;
    }
};