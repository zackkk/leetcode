class Solution {
public:
    // 2d dp
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid[0][0] == 1) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> paths (m, vector<int> (n,0));
        
        paths[0][0] = 1;
        for(int i = 1; i < m; i++){
            paths[i][0] = obstacleGrid[i][0] == 1 ? 0 : paths[i-1][0];
        }
        for(int j = 1; j < n; j++){
            paths[0][j] = obstacleGrid[0][j] == 1 ? 0 : paths[0][j-1];
        }
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j] == 0){
                    paths[i][j] += obstacleGrid[i-1][j] == 0 ? paths[i-1][j] : 0;
                    paths[i][j] += obstacleGrid[i][j-1] == 0 ? paths[i][j-1] : 0;
                }
            }
        }
        return paths[m-1][n-1];
    }
};