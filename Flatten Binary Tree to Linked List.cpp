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
        if(NULL == root) return;
        prev->right = root;
        prev->left = NULL;
        prev = root;
        TreeNode *rightTree = root->right;
        // connect by prev 
        flatten(root->left);
        flatten(rightTree);
    }
};