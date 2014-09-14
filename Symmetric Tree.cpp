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
    // recursion? stuck --->>> stack
    bool isSymmetric(TreeNode *root) {
        if(NULL == root)
            return true;
        stack<TreeNode*> lStack;
        stack<TreeNode*> rStack;
        lStack.push(root->left);
        rStack.push(root->right);
        
        // can push NULL into stack, so sizes will be the same
        while(!lStack.empty() && !rStack.empty()){
            TreeNode *lTmp = lStack.top(); // can't pop directly
            TreeNode *rTmp = rStack.top();
            lStack.pop();
            rStack.pop();
            if(!lTmp && !rTmp) continue;
            if(!lTmp && rTmp) return false;
            if(lTmp && !rTmp) return false;
            if(lTmp->val != rTmp->val) return false;
            lStack.push(lTmp->left);
            lStack.push(lTmp->right);
            rStack.push(rTmp->right);
            rStack.push(rTmp->left);
        }
        return true;
    }
};