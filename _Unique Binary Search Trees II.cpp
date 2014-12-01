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
    // index trick
    vector<TreeNode *> generateTrees(int n) {
        return helper(1, n);
    }
    
    vector<TreeNode *> helper(int lo, int hi){ // lo, hi trick
        vector<TreeNode*> ret;
        if(lo > hi){
            ret.push_back(NULL);
            return ret;
        }
        
        for(int i = lo; i <= hi; ++i){
            vector<TreeNode*> ls = helper(lo, i-1);
            vector<TreeNode*> rs = helper(i+1, hi);
            for(TreeNode* l : ls){
                for(TreeNode *r : rs){
                    TreeNode *root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }
};