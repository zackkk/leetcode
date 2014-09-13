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
    // bfs
    void connect(TreeLinkNode *root) {
        if(NULL == root) return;
        queue<TreeLinkNode *> q;
        q.push(root);
        while(!q.empty()){
            queue<TreeLinkNode *> q_next;
            TreeLinkNode *prev = NULL;
            while(!q.empty()){
                TreeLinkNode *cur = q.front();
                q.pop();
                if(NULL == prev)
                    prev = cur;
                else{
                    prev->next = cur;
                    prev = cur;
                }
                if(cur->left) q_next.push(cur->left);
                if(cur->right) q_next.push(cur->right);
            }
            q = q_next;
        }
    }
};