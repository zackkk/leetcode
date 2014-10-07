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
    // straight-forward implementation
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> ret;
        vector<int> vec;
        if(root == NULL) return ret;
        helper(ret, vec, root, sum, 0);
        return ret;
    }
    
    void helper(vector<vector<int>> &ret, vector<int> vec, TreeNode *root, int sum, int tmpsum){
        if(root->left == NULL && root->right == NULL){
            if(sum == tmpsum + root->val){
                vec.push_back(root->val);
                ret.push_back(vec);
            }
            return;
        }
        vec.push_back(root->val);
        if(root->left) helper(ret, vec, root->left, sum, tmpsum+root->val);
        if(root->right) helper(ret, vec, root->right, sum, tmpsum+root->val);
    }
};