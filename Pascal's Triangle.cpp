class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ret;
        if(numRows == 0) return ret;
        
        vector<int> v1(1, 1);
        ret.push_back(v1);
        if(numRows == 1) return ret;
        
        vector<int> v2(2, 1);
        ret.push_back(v2);
        if(numRows == 2) return ret;
        
        for(int i = 3; i <= numRows; ++i){
            vector<int> vi (1, 1);
            for(int j = 1; j < v2.size(); ++j)
                vi.push_back(v2[j] + v2[j-1]);
            vi.push_back(1);
            v2 = vi;
            ret.push_back(vi);
        }
        return ret;
    }
}; 