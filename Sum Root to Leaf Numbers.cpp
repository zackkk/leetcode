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
    int sum = 0;
public:
    int sumNumbers(TreeNode *root) {
        if(root == NULL) return 0;
        helper(root, 0);
        return sum;
    }
    
    void helper(TreeNode *root, int value){
        if(root->left == NULL && root->right == NULL){
            sum += (root->val + value);
            return;
        }
        
        if(root->left)  helper(root->left, (value + root->val) * 10);
        if(root->right) helper(root->right, (value + root->val) * 10);
    }
};