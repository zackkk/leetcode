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
TreeNode *prev = new TreeNode(-1);
public:
    // pre-order & prev pointer
    void flatten(TreeNode *root) {
        if(root == NULL) return;
        
        prev->right = root;
        prev->left = NULL;
        prev = root;
        
        // connect by prev 
        TreeNode *rightTree = root->right;
        flatten(root->left);
        flatten(rightTree);
    }
};