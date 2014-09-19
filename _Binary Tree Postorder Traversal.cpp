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
    // stack for iterative traversal
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ret;
        helper(ret, root);
        return ret;
    }
    void helper(vector<int> &ret, TreeNode *root){
        if(NULL == root) return;
        helper(ret, root->left);
        helper(ret, root->right);
        ret.push_back(root->val);
    }
};