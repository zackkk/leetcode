class Solution {
public:
    // dfs
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int> > ret;
        vector<int> vec;
        helper(ret, vec, num, target, 0, 0);
        
        // get rid of duplicates
        set<vector<int>> mySet;
        for(int i = 0; i < ret.size(); i++)
            mySet.insert(ret[i]);
        ret.clear();
        ret.assign(mySet.begin(), mySet.end());
        return ret;
    }
    
    void helper(vector<vector<int>> &ret, vector<int> vec, vector<int> &num, int target, int sum, int cur){
        
        if(sum == target) {
            ret.push_back(vec);
            return;
        }
        
        for(int i = cur; i < num.size(); i++){
            if(sum + num[i] <= target){
                vec.push_back(num[i]);
                helper(ret, vec, num, target, sum+num[i], i+1);
                vec.pop_back();
            }
        }
    }
};