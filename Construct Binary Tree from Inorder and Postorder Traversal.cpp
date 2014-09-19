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
    // list all elements of inorder & postorder; use index to traverse
    // construct procedure: root->left->right
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.size() == 0 || postorder.size() == 0 || inorder.size() != postorder.size()){
            return NULL;
        }
        // <val, pos>
        map<int, int> myMap;
        for(int i = 0; i < inorder.size(); i++){
            myMap[inorder[i]] = i;
        }
        return helper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, myMap);
    }
    TreeNode *helper(vector<int> &inorder, int in_l, int in_h, vector<int> &postorder, int post_l, int post_h, map<int, int> &myMap){
        if(in_l > in_h || post_l > post_h){
            return NULL;
        }
        
        int rootVal = postorder[post_h];
        int in_rootPos = myMap[rootVal];
        TreeNode *root = new TreeNode(rootVal);
        
        root->left = helper(inorder, in_l, in_rootPos-1, postorder, post_l, post_l+(in_rootPos-1-in_l), myMap);
        root->right = helper(inorder, in_rootPos+1, in_h, postorder, post_l+(in_rootPos-1-in_l)+1, post_h-1, myMap);
        return root;
    }
};