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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > ret;
        if(root == NULL) return ret;
        
        queue<TreeNode*> cur_q;
        cur_q.push(root);
        
        while(!cur_q.empty()){
            queue<TreeNode*> nt_q;
            vector<int> v;
            
            while(!cur_q.empty()){
                TreeNode *tmp = cur_q.front();
                cur_q.pop();
                v.push_back(tmp->val);
                
                if(tmp->left) nt_q.push(tmp->left);
                if(tmp->right) nt_q.push(tmp->right);
            }
            
            cur_q = nt_q;
            ret.push_back(v);
        }
        
        reverse(ret.begin(), ret.end());
        return ret;
    }
};