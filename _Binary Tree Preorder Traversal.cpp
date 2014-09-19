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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ret;
        helper(root, ret);
        return ret;
    }
    void helper(TreeNode *root, vector<int> &ret){
        if(NULL == root)
            return;
        ret.push_back(root->val);
        helper(root->left, ret);
        helper(root->right, ret);
    }
};