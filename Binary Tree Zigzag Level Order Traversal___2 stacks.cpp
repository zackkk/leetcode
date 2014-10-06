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
    // think reversely in two stacks :
    //      expected result: 4,6,2,1,3,5,7 (seven elements BST)
    //      level traversal in stacks:
    //                              4         | left,right 
    //                              2,6     <-|
    //                              2,6       | right,left
    //                              7,5,3,1 <-|
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> ret;
        if(root == NULL) return ret;
        
        stack<TreeNode *> stk;
        stk.push(root);
        bool normalOrder = true;
        
        while(!stk.empty()){
            vector<int> vec;
            stack<TreeNode *> stk_next;
            while(!stk.empty()){
                TreeNode *tn = stk.top();
                stk.pop();
                vec.push_back(tn->val);
                
                if(normalOrder){
                    if(tn->left) stk_next.push(tn->left);
                    if(tn->right) stk_next.push(tn->right);
                }
                else{
                    if(tn->right) stk_next.push(tn->right);
                    if(tn->left) stk_next.push(tn->left);
                }
            }
            ret.push_back(vec);
            normalOrder = !normalOrder;
            stk = stk_next;
        }
        
        return ret;
    }
};