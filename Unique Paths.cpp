class Solution {
public:
    // 2d dp, path
    int uniquePaths(int m, int n) {
        vector<vector<int>> paths(m, vector<int> (n,0));
        for(int row = 0; row < m; row++) paths[row][0] = 1;
        for(int col = 0; col < n; col++) paths[0][col] = 1;
        for(int row = 1; row < m; row++){
            for(int col = 1; col < n; col++){
                paths[row][col] = paths[row-1][col] + paths[row][col-1];
            }
        }
        return paths[m-1][n-1];
    }
};