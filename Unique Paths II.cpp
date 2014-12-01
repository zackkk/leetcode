class Solution {
public:
    // 2d dp
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        if(m == 0) return 0;
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1) return 0;
        
        vector<vector<int>> ways (m, vector<int>(n, 0));
        ways[0][0] = 1;
        for(int i = 1; i < m; ++i) ways[i][0] = obstacleGrid[i][0] == 1 ? 0 : ways[i-1][0];
        for(int j = 1; j < n; ++j) ways[0][j] = obstacleGrid[0][j] == 1 ? 0 : ways[0][j-1];
        
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                if(obstacleGrid[i][j]) continue;
                ways[i][j] = obstacleGrid[i-1][j] ? ways[i][j] : ways[i][j] + ways[i-1][j];
                ways[i][j] = obstacleGrid[i][j-1] ? ways[i][j] : ways[i][j] + ways[i][j-1];
            }
        }
        return ways[m-1][n-1];
    }
};