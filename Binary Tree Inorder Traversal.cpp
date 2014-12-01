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
    vector<int> inorderTraversal(TreeNode *root) {
        TreeNode *cur = root;
        stack<TreeNode*> stk;
        vector<int> ret;
        
        while(cur || !stk.empty()){
            while(cur){
                stk.push(cur);
                cur = cur->left;
            }
            
            if(!stk.empty()){
                TreeNode *tmp = stk.top();
                stk.pop();
                ret.push_back(tmp->val);
                cur = tmp->right;
            }
        }
        
        return ret;
    }
};