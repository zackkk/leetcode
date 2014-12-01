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
    // two stacks, think reversely
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode*> output_stk;
        stack<TreeNode*> cur_stk;
        vector<int> ret;
        if(root == NULL) return ret;
        
        cur_stk.push(root);
        while(!cur_stk.empty()){
            TreeNode *tmp = cur_stk.top();
            output_stk.push(tmp);
            cur_stk.pop();
            
            if(tmp->left) cur_stk.push(tmp->left);
            if(tmp->right) cur_stk.push(tmp->right);
        }
        
        while(!output_stk.empty()){
            TreeNode *tmp = output_stk.top();
            output_stk.pop();
            ret.push_back(tmp->val);
        }
        
        return ret;
    }
};