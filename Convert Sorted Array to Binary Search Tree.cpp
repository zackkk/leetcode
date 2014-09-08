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
    // improve: use index
    TreeNode *sortedArrayToBST(vector<int> &num) {
        int len = num.size(); // vector has no length() member func
        if(len == 0)
            return NULL;
        TreeNode *root = new TreeNode(num[len/2]);
        
        vector<int> leftVec; 
        for(int i = 0; i < len/2; i++)
            leftVec.push_back(num[i]);
            
        vector<int> rightVec;
        for(int i = len/2+1; i < len; i++)
            rightVec.push_back(num[i]);
            
        root->left = sortedArrayToBST(leftVec);
        root->right = sortedArrayToBST(rightVec);
        return root;
    }
};