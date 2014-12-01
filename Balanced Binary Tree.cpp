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
    bool isBalanced(TreeNode *root) {
        return maxDepth(root, 0) != -1;
    }
    
    int maxDepth(TreeNode *root, int depth){
        if(root == NULL) return depth;
        int left_depth = maxDepth(root->left, depth + 1);
        int right_depth = maxDepth(root->right, depth + 1);
        if(left_depth == -1 || right_depth == -1 || abs(left_depth - right_depth) > 1) 
            return -1;
        else 
            return max(left_depth, right_depth);
    }
};