class Solution {
public:
    // 2d dp
    int numDistinct(string S, string T) {
        int m = S.size();
        int n = T.size();
        
        vector<vector<int>> dp (m+1, vector<int>(n+1, 0));
        
        for(int i = 0; i <= m; ++i) dp[i][0] = 1;
        
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                dp[i][j] = dp[i-1][j];
                if(S[i-1] == T[j-1])
                    dp[i][j] += dp[i-1][j-1];
            }
        }
        return dp[m][n];
    }
};