class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        vector<int> prev_row = grid[0];
        for(int j = 1; j < n; ++j)
            prev_row[j] += prev_row[j-1];
        
        for(int i = 1; i < m; ++i){
            vector<int> cur_row (n, 0);
            for(int j = 0; j < n; ++j){
                cur_row[j] = j == 0 ? prev_row[0] + grid[i][0] : min(prev_row[j], cur_row[j-1]) + grid[i][j];
            }
            prev_row = cur_row;
        }
        return prev_row[n-1];
    }
};