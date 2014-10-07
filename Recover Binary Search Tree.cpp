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
    TreeNode *first = NULL;
    TreeNode *second = NULL;
    TreeNode *prev = NULL;
public:
    // prev pointer + inorder, write all numbers in a line
    void recoverTree(TreeNode *root) {
        inorderTraverse(root);
        
        // swap back to normal
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
    
    void inorderTraverse(TreeNode *root){
        if(root == NULL) return;
        
        inorderTraverse(root->left);
        
        if(prev != NULL && root->val < prev->val){
            first = first == NULL ? prev : first;
            second = root;
        }
        prev = root;
        
        inorderTraverse(root->right);
    }
};