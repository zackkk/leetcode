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
    // stack, continue traversing left, turn to the right 
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ret;
        stack<TreeNode *> stk;
        TreeNode *cur = root;
        
        while(cur != NULL || !stk.empty()){
            while(cur != NULL){
                ret.push_back(cur->val);
                stk.push(cur);
                cur = cur->left;
            }
            if(!stk.empty()){
                cur = stk.top();
                stk.pop();
                cur = cur->right;
            }
        }
        return ret;
    }
};