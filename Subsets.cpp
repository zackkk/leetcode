class Solution {
public:
    // 1. not dfs... ---> iteration
    // 2. bit 2^n possibilities 
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int>> prev;
        vector<int> tmp;
        prev.push_back(tmp);
        if(S.empty()) return prev;
        for(int i = 0; i < S.size(); i++){
            vector<vector<int>> cur = prev;
            for(int j = 0; j < prev.size(); j++){
                vector<int> tmp = prev[j];
                tmp.push_back(S[i]);
                cur.push_back(tmp);
            }
            prev = cur;
        }
        return prev;
    }
};