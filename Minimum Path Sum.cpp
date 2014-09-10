class Solution {
public:
    // straight forward 2d dp
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m == 0 && n == 0) return 0;
        
        int minPath [m][n];
        minPath[0][0] = grid[0][0];
        for(int i = 1; i < m; i++) minPath[i][0] = minPath[i-1][0] + grid[i][0];
        for(int j = 1; j < n; j++) minPath[0][j] = minPath[0][j-1] + grid[0][j];
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                minPath[i][j] = min(minPath[i-1][j], minPath[i][j-1]) + grid[i][j];
            }
        }
        return minPath[m-1][n-1];
    }
};