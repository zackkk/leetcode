class Solution {
public:
    // straight forward solution
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> ret;
        if(numRows == 0) return ret;
        
        vector<int> prev;
        prev.push_back(1);
        ret.push_back(prev);
        if(numRows == 1) return ret;
        
        prev.push_back(1);
        ret.push_back(prev);
        if(numRows == 2) return ret;
        
        for(int i = 3; i <= numRows; i++){
            vector<int> cur;
            cur.push_back(1);
            for(int j = 1; j < prev.size(); j++)
                cur.push_back(prev[j] + prev[j-1]);
            cur.push_back(1);
            prev = cur;
            ret.push_back(cur);
        }
        return ret;
    }
};