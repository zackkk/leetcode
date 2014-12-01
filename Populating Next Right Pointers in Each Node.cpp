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
    if(root == NULL) return;
        
        TreeLinkNode *cur = root;
        while(cur->left){
            TreeLinkNode *traverser = cur;
            while(traverser){
                traverser->left->next = traverser->right;
                traverser->right->next = traverser->next ? traverser->next->left : NULL;
                traverser = traverser->next; 
            }
            cur = cur->left;
        }
    }
};