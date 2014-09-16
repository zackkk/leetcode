class Solution {
public:
    // min path
    int minimumTotal(vector<vector<int> > &triangle) {
        if(0 == triangle.size()) return 0;
        if(1 == triangle.size()) return triangle[0][0];
            
        vector<int> prev;
        prev.push_back(triangle[0][0]);
        
        for(int i = 1; i < triangle.size(); i++){
            vector<int> cur;
            for(int j = 0; j < triangle[i].size(); j++){
                int min = INT_MAX;
                min = 0 <= j-1 && j-1 < prev.size() && prev[j-1] < min ? prev[j-1] : min;
                min = 0 <= j   && j   < prev.size() && prev[j]   < min ? prev[j]   : min;
                //min = 0 <= j+1 && j+1 < prev.size() && prev[j+1] < min ? prev[j+1] : min;
                cur.push_back(min + triangle[i][j]);
            }
            prev = cur;
        }
        
        int retMin = INT_MAX;
        for(int i = 0; i < triangle.size(); i++)
            retMin = min(retMin, prev[i]);
        return retMin;
    }
};