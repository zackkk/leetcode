class Solution {
public:
    // dfs
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> ret;
        if(n < k || n == 0 || k == 0) return ret;
        vector<int> vec;
        dfs(ret, vec, n, k, 1);
        return ret;
    }
    void dfs(vector<vector<int>> &ret, vector<int> &vec, int n, int k, int cur){
        if(k == vec.size()){
            ret.push_back(vec);
            return;
        }
        for(int i = cur; i <= n; i++){
            vec.push_back(i);
            dfs(ret, vec, n, k, i+1);
            vec.pop_back();
        }
    }
};