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
private:
    int max_sum = INT_MIN;// corner case: negative val
public:
    int maxPathSum(TreeNode *root) {
        if(!root) return 0;
        singlePathSum(root);
        return max_sum;
    }
    
    int singlePathSum(TreeNode *root){
        if(!root) return 0; 
        
        int l = singlePathSum(root->left);
        int r = singlePathSum(root->right);
        
        int ret = max(root->val, max(root->val + l, root->val + r));
        
        max_sum = max(max_sum, ret);
        max_sum = max(max_sum, root->val + l + r);
        return ret;
    }
};



