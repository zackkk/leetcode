class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<int> v;
        vector<vector<int>> ret;
        dfs(num, target, v, ret, 0, 0);
        
        set<vector<int>> s;
        for(vector<int> tmp : ret) s.insert(tmp);
        ret.clear();
        ret.assign(s.begin(), s.end());
        return ret;
    }
    
    void dfs(vector<int> &candidates, int target, vector<int> &v, vector<vector<int>> &ret, int sum, int cur){
        if(sum == target){
            ret.push_back(v);
            return;
        }
        
        for(int i = cur; i < candidates.size(); ++i){
            if(sum + candidates[i] > target) continue;
            v.push_back(candidates[i]);
            dfs(candidates, target, v, ret, sum+candidates[i], i+1); // diff: i+1
            v.pop_back();
        }
    }
};