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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        map<int, int> m;// value->index
        for(int i = 0; i < inorder.size(); ++i) // where bug happens
            m[inorder[i]] = i;
        return helper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, m);
    }
    
    TreeNode *helper(vector<int> &inorder, int in_l, int in_h, vector<int> &postorder, int po_l, int po_h, map<int, int> &m){
        if(in_l > in_h || po_l > po_h) return NULL;
        
        int root_val = postorder[po_h];
        TreeNode *root = new TreeNode(root_val);
        int index = m[root_val];
        
        root->left = helper(inorder, in_l, index-1, postorder, po_l, po_l+(index-1-in_l), m);
        root->right = helper(inorder, index+1, in_h, postorder, po_l+(index-1-in_l)+1, po_h-1, m);
        return root;
    }
};