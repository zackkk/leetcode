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
    int minDepth(TreeNode *root) {
        if(root == NULL) return 0;
        return helper(root);
    }
    int helper(TreeNode *root){
        if(root == NULL)  // corner case: root has no right child 
            return INT_MAX;
        if(root->left == NULL && root->right == NULL)
            return 1;
        return min(helper(root->left), helper(root->right)) + 1;
    }
};