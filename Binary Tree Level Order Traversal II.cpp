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
    // bfs
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> ret;
        if(NULL == root) return ret;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            queue<TreeNode *> q_next;
            vector<int> vec;
            // save current level and get the next level
            while(!q.empty()){
                TreeNode *tn = q.front();
                q.pop();
                vec.push_back(tn->val);
                if(tn->left)  q_next.push(tn->left); // can't push NULL
                if(tn->right) q_next.push(tn->right);
            }
            ret.push_back(vec);
            q = q_next;
        }
    
        reverse(ret.begin(), ret.end()); // use STL
        return ret;
    }
};