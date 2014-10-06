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
    // think reversely in two stacks: 
    //      draw the tree  : post order traversal of a binary search tree
    //      expected output: 1,3,2,5,7,6,4 
    //      output in stack: 4,6,7,5,2,3,1
    //      current   stack: level order traversal.
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ret;
        if(root == NULL) return ret;
        stack<TreeNode *> cur, output;
        cur.push(root);
        while(!cur.empty()){
            TreeNode *tn = cur.top();
            cur.pop();
            output.push(tn);
            if(tn->left) cur.push(tn->left);
            if(tn->right) cur.push(tn->right);
        }
        
        while(!output.empty()){
            TreeNode *tn = output.top();
            output.pop();
            ret.push_back(tn->val);
        }
        return ret;
    }
};