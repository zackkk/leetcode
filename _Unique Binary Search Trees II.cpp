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
    // dfs + recursion
    vector<TreeNode *> generateTrees(int n) {
        return generate(1, n);        
    }
    vector<TreeNode *> generate(int low, int high){
        vector<TreeNode *> nodes;
        if(low > high){
            nodes.push_back(NULL);
            return nodes;
        }
        
        for(int mid = low; mid <= high; mid++){
            vector<TreeNode *> leftNodes = generate(low, mid-1);
            vector<TreeNode *> rightNodes = generate(mid+1, high);
            for(TreeNode *left : leftNodes){
                for(TreeNode *right : rightNodes){
                    TreeNode *root = new TreeNode(mid);
                    root->left = left;
                    root->right = right;
                    nodes.push_back(root);
                }
            }
        }
        return nodes;
    }
};





