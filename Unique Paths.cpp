class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 0 || n == 0) return 0;
        vector<int> prev_row (n, 1);
        
        for(int i = 1; i < m; ++i){
            vector<int> cur_row (n, 0);
            for(int j = 0; j < n; ++j){
                cur_row[j] = j == 0 ? 1 : cur_row[j-1] + prev_row[j];
            }
            prev_row = cur_row;
        }
        return prev_row[n-1];
    }
};