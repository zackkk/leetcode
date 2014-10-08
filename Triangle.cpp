class Solution {
public:
    // min path, triangle ---> left align
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.size() == 0) return 0;
        if(triangle.size() == 1) return triangle[0][0];
            
        vector<int> prev;
        prev.push_back(triangle[0][0]);
        
        for(int i = 1; i < triangle.size(); i++){
            vector<int> cur;
            for(int j = 0; j < triangle[i].size(); j++){
                int tmp = INT_MAX;
                if(0 <= j-1 && j-1 < prev.size()) tmp = min(tmp, prev[j-1]);
                if(0 <= j   && j   < prev.size()) tmp = min(tmp, prev[j]);
                cur.push_back(tmp + triangle[i][j]);
            }
            prev = cur;
        }
        
        int ret = INT_MAX;
        for(int i = 0; i < triangle.size(); i++)
            ret = min(ret, prev[i]);
        return ret;
    }
};