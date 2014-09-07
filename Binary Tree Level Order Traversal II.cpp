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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // bfs
        vector<vector<int>> ret;
        if(NULL == root) return ret;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            queue<TreeNode *> q_next;
            vector<int> vec;
            // save current level and get next level
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
        vector<vector<int>> retRes;
        for(int i = ret.size()-1; i >= 0; i--){
            retRes.push_back(ret[i]);
        }
        return retRes;
    }
};