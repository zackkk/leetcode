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
    // use two stacks instead of queue, magic!
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> ret;
        if(root == NULL){ 
            return ret;
        }
        
        stack<TreeNode *> cur;
        cur.push(root);
        bool normalOrder = true;
        
        while(!cur.empty()){
            vector<int> vec;
            stack<TreeNode *> next;
            while(!cur.empty()){
                TreeNode *tn = cur.top();
                cur.pop();
                vec.push_back(tn->val);
                
                if(normalOrder){
                    if(tn->left) next.push(tn->left);
                    if(tn->right) next.push(tn->right);
                }
                else{
                    if(tn->right) next.push(tn->right);
                    if(tn->left) next.push(tn->left);
                }
            }
            ret.push_back(vec);
            normalOrder = !normalOrder;
            cur = next;
        }
        
        return ret;
    }
};