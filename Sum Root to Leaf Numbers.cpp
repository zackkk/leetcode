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
        if(NULL == root) return 0;
        helper(root, 0);
        return sum;
    }
    void helper(TreeNode *root, int tmpSum){
        // leaf
        if(NULL == root->left && NULL == root->right){
            sum += (tmpSum + root->val);
            return;
        }
        if(NULL != root->left)
            helper(root->left, (tmpSum + root->val) * 10);
        if(NULL != root->right)
            helper(root->right, (tmpSum + root->val) * 10);
    }
};Sum Root to Leaf Numbers