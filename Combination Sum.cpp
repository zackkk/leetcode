class Solution {
public:
    // dfs
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > ret;
        if(candidates.size() == 0) return ret;
        vector<int> vec;
        sort(candidates.begin(), candidates.end());
        helper(ret, vec, candidates, target, 0, 0);
        return ret;
    }
    void helper(vector<vector<int>> &ret, vector<int> vec, vector<int> &candidates, int target, int sum, int cur){
        if(sum == target){
            ret.push_back(vec);
            return;
        }
        for(int i = cur; i < candidates.size(); i++){
            if(sum + candidates[i] <= target){
                vec.push_back(candidates[i]);
                helper(ret, vec, candidates, target, sum+candidates[i], i);
                vec.pop_back();
            }
        }
    }
};