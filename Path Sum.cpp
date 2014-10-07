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
    bool hasPathSum(TreeNode *root, int sum) {
        if(root == NULL)
            return false;
        if(root->left == NULL && root->right == NULL){
            return root->val == sum ? true : false;
        }
        return (hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val));
    }
};