class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        vector<vector<int>> ret;
        dfs(candidates, target, v, ret, 0, 0);
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
            dfs(candidates, target, v, ret, sum+candidates[i], i);
            v.pop_back();
        }
    }
};