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
    TreeNode *prev = NULL;
public:
    void flatten(TreeNode *root) {
        if(!root) return;
        
        if(prev){
            prev->left = NULL;
            prev->right = root;
        }
        prev = root;
        
        TreeNode *right_child = root->right;
        flatten(root->left);
        flatten(right_child);
    }
};