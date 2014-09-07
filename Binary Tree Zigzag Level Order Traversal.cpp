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
    // use two stacks instead of queue
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> ret;
        if(NULL == root) return ret;
        
        stack<TreeNode *> curLevel;
        curLevel.push(root);
        bool normalOrder = true;
        
        while(!curLevel.empty()){
            vector<int> vec;
            stack<TreeNode *> nextLevel;
            while(!curLevel.empty()){
                TreeNode *tn = curLevel.top();
                curLevel.pop();
                vec.push_back(tn->val);
                
                if(normalOrder){
                    if(tn->left) nextLevel.push(tn->left);
                    if(tn->right) nextLevel.push(tn->right);
                }
                else{
                    if(tn->right) nextLevel.push(tn->right);
                    if(tn->left) nextLevel.push(tn->left);
                }
            }
            ret.push_back(vec);
            normalOrder = !normalOrder;
            curLevel = nextLevel;
        }
        
        return ret;
    }
};