/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(NULL == root || NULL == root->left)
            return;
        
        TreeLinkNode *traverse = root;
        while(NULL != traverse){
            traverse->left->next = traverse->right;
            if(NULL != traverse->next)
                traverse->right->next = traverse->next->left;
            traverse = traverse->next;
        } 
        connect(root->left);
    }
};