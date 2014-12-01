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
    // CC150
    bool isValidBST(TreeNode *root) {
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
    
    bool helper(TreeNode *root, long long lo, long long hi){
        if(root == NULL) return true;
        if(root->val <= lo || root->val >= hi) return false;
        
        return helper(root->left, lo, root->val) && helper(root->right, root->val, hi);
    }
};