class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
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
        
        set<vector<int>> s;
        for(vector<int> vec : ret){ s.insert(vec); }
        ret.clear();
        ret.assign(s.begin(), s.end());
        
        return ret;
    }
};