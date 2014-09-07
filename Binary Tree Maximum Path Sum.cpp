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
    // post-order traverse, negative vals
    int maxPathSum(TreeNode *root) {
        helper(root);
        return maxSum;
    }
    int helper(TreeNode *root){
        if(NULL == root) return 0;
        int leftPathSum = helper(root->left);
        int rightPathSum = helper(root->right);
        // for current node
        int maxSinglePathSum = max(leftPathSum, rightPathSum) + root->val;
        maxSinglePathSum = max(maxSinglePathSum, root->val);
        maxSum = max(maxSum, root->val);
        maxSum = max(maxSum, maxSinglePathSum);
        maxSum = max(maxSum, leftPathSum + rightPathSum + root->val);
        return maxSinglePathSum;
    }
};