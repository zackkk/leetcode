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
int sum = 0;
public:
    int sumNumbers(TreeNode *root) {
        if(root == NULL) return 0;
        helper(root, 0);
        return sum;
    }
    
    void helper(TreeNode *root, int tmpsum){
        // leaf
        if(root->left == NULL && root->right == NULL){
            sum += (tmpsum + root->val);
            return;
        }
        if(root->left != NULL)
            helper(root->left, (tmpsum + root->val) * 10);
        if(root->right != NULL)
            helper(root->right, (tmpsum + root->val) * 10);
    }
};