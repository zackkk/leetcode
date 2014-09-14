class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int>> prev;
        vector<int> tmp;
        prev.push_back(tmp);
        if(0 == S.size())
            return prev;
            
        for(int i = 0; i < S.size(); i++){
            vector<vector<int>> cur = prev;
            for(int j = 0; j < prev.size(); j++){
                vector<int> tmp = prev[j];
                tmp.push_back(S[i]);
                cur.push_back(tmp);
            }
            prev = cur;
        }
        
        // use set to get rid of duplicates
        set<vector<int>> mySet;
        for(int i = 0; i < prev.size(); i++)
            mySet.insert(prev[i]);
        vector<vector<int>> ret;
        ret.assign(mySet.begin(), mySet.end()); // new
        return ret;
    }
};