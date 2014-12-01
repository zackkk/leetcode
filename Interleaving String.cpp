class Solution {
public:
    // dp: unique path !!!!!! 
    /*         
     *          *   a   a   b   c   c (s2)
     *(s1)  *   /   /   /
     *      d           /   /
     *      b           /   /   /
     *      b           /       /
     *      c           /   /   /
     *      a                   /   /
     */
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if(m + n != s3.size()) return false;
        
        vector<vector<bool>> dp (m+1, vector<bool> (n+1, false));
        dp[0][0] = true;
        for(int i = 1; i <= m; ++i) dp[i][0] = (dp[i-1][0] && s1[i-1] == s3[i-1]) ? true : false;
        for(int j = 1; j <= n; ++j) dp[0][j] = (dp[0][j-1] && s2[j-1] == s3[j-1]) ? true : false;
        
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                if(dp[i-1][j] && s1[i-1] == s3[i+j-1]) dp[i][j] = true;
                if(dp[i][j-1] && s2[j-1] == s3[i+j-1]) dp[i][j] = true;
            }
        }
        return dp[m][n];
    }
};