class Solution {
public:
    // Palindrome Partitioning I: list all possible partitions
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> p (n, vector<bool>(n, false)); // is palindrome
        vector<int> dp (n, 0);
        
        for(int j = 0; j < n; ++j){
            dp[j] = j;
            for(int i = 0; i <= j; ++i){
                if(s[i] == s[j] && (j - i <= 1 || p[i+1][j-1]))
                    p[i][j] = true;
                if(p[i][j])
                    dp[j] = i == 0 ? 0 : min(dp[j], dp[i-1]+1);
            }
        }
        return dp[n-1];
    }
};