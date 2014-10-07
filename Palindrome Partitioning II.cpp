class Solution {
public:
    // 1d dp
    int minCut(string s) {
        int len = s.size();
        vector<vector<bool>> p (len, vector<bool> (len, false)); // is palindrome
        vector<int> dp (len, 0);
        
        for(int j = 0; j < len; j++){ 
            dp[j] = j;
            for(int i = 0; i <= j; i++){
                if((j-i <= 1 || p[i+1][j-1]) && s[i] == s[j]) 
                    p[i][j] = true; 
                if(p[i][j])
                    dp[j] = i == 0 ? 0 : min(dp[j], dp[i-1]+1);
            }
        }
        return dp[len-1];
    }
};