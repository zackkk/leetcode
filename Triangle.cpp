class Solution {
public:
    // min path, triangle ---> left align
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        if(n == 0) return 0;
        
        vector<int> prev;
        prev.push_back(triangle[0][0]);
        
        for(int i = 1; i < n; ++i){
            
            vector<int> cur = triangle[i];
            for(int j = 0; j < cur.size(); ++j){
                if(j == 0) 
                    cur[j] += prev[j];
                else if(j == cur.size() - 1)
                    cur[j] += prev[j - 1];
                else
                    cur[j] += (min(prev[j-1], prev[j]));
            }
            
            prev = cur;
        }
        
        int ret = INT_MAX;
        for(int i : prev) ret = min(ret, i);
        return ret;
    }
};