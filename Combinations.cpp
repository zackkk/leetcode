class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ret;
        if(n < k || n == 0) return ret;
        vector<int> v;
        dfs(ret, v, n, k, 1);
        return ret;
    }
    
    void dfs(vector<vector<int>> &ret, vector<int> &v, int n, int k, int cur){
        if(v.size() == k){
            ret.push_back(v);
            return;
        }
        
        for(int i = cur; i <= n; ++i){
            v.push_back(i);
            dfs(ret, v, n, k, i+1); // bug happened here
            v.pop_back();
        }
    }
};