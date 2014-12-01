class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<int> rows (n, 0);
        vector<vector<string>> ret;
        string s = "";
        for(int i = 0; i < n; ++i) s += ".";
        dfs(rows, 0, n, ret, s);
        return ret;
    }
    
    void dfs(vector<int> &rows, int cur, int n, vector<vector<string>> &ret, string &s){
        if(cur == n){
            vector<string> v (n, s);
            for(int i = 0; i < n; ++i) v[i][rows[i]] = 'Q';
            ret.push_back(v);
            return;
        }
        
        for(int i = 0; i < n; ++i){
            if(isValid(rows, cur, i)){
                rows[cur] = i;
                dfs(rows, cur+1, n, ret, s);
            }
        }
    }
    
    bool isValid(vector<int> &rows, int cur, int val){
        for(int i = 0; i < cur; ++i){
            if(rows[i] == val || abs(cur - i) == abs(val - rows[i]))
                return false;
        }
        return true;
    }
};