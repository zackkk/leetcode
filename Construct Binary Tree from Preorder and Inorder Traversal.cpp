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
    // tree traverse + index control
    // construct procedure: root->left->right
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.size() == 0 || inorder.size() == 0 || preorder.size() != inorder.size()){
            return NULL;
        }
        // <val, pos>
        map<int, int> myMap;
        for(int i = 0; i < inorder.size(); i++){
            myMap[inorder[i]] = i;
        }
        return helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, myMap);
    }
    // only use index, otherwise need to get sub-vector
    TreeNode *helper(vector<int> &preorder, int pre_l, int pre_h, vector<int> &inorder, int in_l, int in_h, map<int, int> &myMap){
        if(pre_l > pre_h || in_l > in_h){
            return NULL;
        }
        
        int rootVal = preorder[pre_l];
        TreeNode *root = new TreeNode(rootVal);
        int in_rootPos = myMap[rootVal];
        
        root->left = helper(preorder, pre_l+1, pre_l+1+(in_rootPos-1-in_l), inorder, in_l, in_rootPos-1, myMap);
        root->right = helper(preorder, pre_l+1+(in_rootPos-1-in_l)+1, pre_h, inorder, in_rootPos+1, in_h, myMap);
        return root;
    }
};