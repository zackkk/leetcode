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
        stack<TreeNode*> stk;
        TreeNode *cur = root;
        
        while(cur || !stk.empty()){
            while(cur){
                ret.push_back(cur->val);
                stk.push(cur);
                cur = cur->left;
            }
            if(!stk.empty()){
                TreeNode *tmp = stk.top();
                stk.pop();
                cur = tmp->right;
            }
        }
        return ret;
    } 
};