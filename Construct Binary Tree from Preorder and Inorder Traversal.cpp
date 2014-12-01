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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        map<int, int> m;
        for(int i = 0; i < inorder.size(); ++i){
            m[inorder[i]] = i;
        }
        return helper(inorder, 0, inorder.size()-1, preorder, 0, preorder.size()-1, m);
    }
    
    TreeNode *helper(vector<int> &inorder, int in_l, int in_h, vector<int> &preorder, int pre_l, int pre_h, map<int, int> &m){
        if(in_l > in_h || pre_l > pre_h) return NULL;
        
        int root_val = preorder[pre_l];
        TreeNode *root = new TreeNode(root_val);
        int index = m[root_val];
        
        root->left = helper(inorder, in_l, index-1, preorder, pre_l+1, pre_l+1 + (index-1-in_l), m);
        root->right = helper(inorder, index+1, in_h, preorder, pre_l+1 + (index-1-in_l)+1, pre_h, m);
        return root;
    }
};