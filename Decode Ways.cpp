class Solution {
public:
    // dp ---> case1: one char, case2: two chars
    // climb stairs !!!!!!!!!!!!!
    int numDecodings(string s) {
        if(s.size() == 0) return 0;
        vector<int> dp (s.size()+1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1; // '0' has no mapping
        for(int i = 2; i <= s.size(); i++){
            // "climb" one step
            if(s[i-1] != '0') // s[i-1] maps to ith char
                dp[i] += dp[i-1]; 
            // "climb" two steps
            int twoDigits = (s[i-2] - '0') * 10 + (s[i-1] - '0');
            if(10 <= twoDigits && twoDigits <= 26)
                dp[i] += dp[i-2];
        }
        return dp[s.size()];
    }
};