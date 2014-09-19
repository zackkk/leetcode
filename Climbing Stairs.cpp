class Solution {
public:
    // 1d dp, we can get to stair case N either from N-2 (2 steps) or N-1 (1 step)
    int climbStairs(int n) {
        vector<int> dp (n+1, 0);
        if(n <= 2){
            return n;
        }
        
        dp[1] = 1;
        dp[2] = 2; // 1-1 or 2
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2]; 
        }
        return dp[n];
    }
};