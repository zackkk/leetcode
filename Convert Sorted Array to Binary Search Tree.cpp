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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return helper(num, 0, num.size()-1);
    }
    
    TreeNode *helper(vector<int> &num, int lo, int hi){
        if(lo > hi) return NULL;
        int mi = lo + (hi - lo) / 2;
        TreeNode *root = new TreeNode(num[mi]);
        root->left = helper(num, lo, mi-1);
        root->right = helper(num, mi+1, hi);
        return root;
    }
};