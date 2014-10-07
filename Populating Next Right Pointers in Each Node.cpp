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
    // assign connections for the next level
    void connect(TreeLinkNode *root) {
        if(root == NULL || root->left == NULL)
            return;
        
        TreeLinkNode *traverse = root;
        while(traverse != NULL){
            traverse->left->next  = traverse->right;
            traverse->right->next = traverse->next != NULL ? traverse->next->left : NULL;
            traverse = traverse->next;
        } 
        connect(root->left);
    }
};