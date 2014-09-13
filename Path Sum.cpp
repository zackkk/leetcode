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
    bool hasPathSum(TreeNode *root, int sum) {
        if(NULL == root)
            return false;
        if(NULL == root->left && NULL == root->right){
            if(root->val == sum)
                return true;
            else
                return false;
        }
        return (hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val));
    }
};