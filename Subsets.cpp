class Solution {
public:
    // 1. not dfs... ---> iteration
    // 2. bit 2^n possibilities 
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > ret;
        vector<int> v;
        ret.push_back(v);
        
        for(int i : S){
            vector<vector<int> > tmp = ret;
            for(vector<int> vec : tmp){
                vec.push_back(i);
                ret.push_back(vec);
            }
        }
        
        return ret;
    }
};