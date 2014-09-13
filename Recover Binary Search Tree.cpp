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
TreeNode *first = NULL;
TreeNode *second = NULL;
TreeNode *prev = NULL;
public:
    // prev pointer + inorder,,, write all numbers in a line
    void recoverTree(TreeNode *root) {
        inorderTraverse(root);
        // swap back to normal
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
    void inorderTraverse(TreeNode *root){
        if(NULL == root) return;
        
        inorderTraverse(root->left);
        
        if(NULL != prev && root->val < prev->val){
            if(NULL == first){
                first = prev;
            }
            second = root;
        }
        prev = root;
        
        inorderTraverse(root->right);
    }
};