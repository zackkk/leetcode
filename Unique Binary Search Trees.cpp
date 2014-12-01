class Solution {
public:
    // 1d dp, list cases for n=1, n=2, n=3... to find out the rule
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; ++i){
            for(int j = 1; j <= i; ++j)
                dp[i] += dp[j-1] * dp[i-j];
        }
        return dp[n];
    }
};