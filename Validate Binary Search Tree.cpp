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
    bool isValidBST(TreeNode *root) {
        return helper(root, INT_MIN, INT_MAX);
    }
    
    bool helper(TreeNode *root, int lowerBound, int upperBound){
        if(NULL == root) return true;
        if(root->val <= lowerBound) return false;
        if(root->val >= upperBound) return false;
        return helper(root->left, lowerBound, root->val) &&
               helper(root->right, root->val, upperBound);
    }
};