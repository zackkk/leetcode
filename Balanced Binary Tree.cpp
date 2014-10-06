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
    // post-order traverse & the usage of -1, use return value to avoid duplicate calculation. traverse once only
    bool isBalanced(TreeNode *root) {
        return getDepth(root) != -1;
    }
    int getDepth(TreeNode *root){
        if(root == NULL) return 0;
        
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        if(left == -1 || right == -1 || abs(left - right) > 1)
            return -1;
        else
            return max(left, right) + 1;
    }
};