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
int maxSum = INT_MIN;
public:
    // post-order traverse, negative values
    int maxPathSum(TreeNode *root) {
        helper(root);
        return maxSum;
    }
    int helper(TreeNode *root){
        if(NULL == root){ 
            return 0;
        }
        
        int left = helper(root->left);
        int right = helper(root->right);
        int ret = max(root->val, max(left, right) + root->val); // return max "single path" sum
        
        maxSum = max(maxSum, ret);
        maxSum = max(maxSum, left + right + root->val); // start at left and end at right
        return ret;
    }
};