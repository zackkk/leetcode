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
    // one stack, push left, turn to right 
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret; 
        stack<TreeNode *> stk;
        TreeNode *cur = root;
        
        while(cur != NULL || !stk.empty()){
            while(cur != NULL){
                stk.push(cur);
                cur = cur->left;
            }
            if(!stk.empty()){  // bug happened here, used "while"
                cur = stk.top();
                stk.pop();
                ret.push_back(cur->val);
                cur = cur->right;  
            }
        }
        return ret;
    }
};