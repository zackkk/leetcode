class Solution {
public:
    // 1d dp ---> dp[i] donates s[0, i-1] can be segmented
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size();
        vector<bool> dp (n, false);
        for(int i = 0; i < n; i++){
            if(i == 0 || dp[i-1]){ // can reach 
                for(string str : dict){
                    int len = str.size();
                    if(i + len - 1 < n && s.substr(i, len) == str)
                        dp[i + len -1] = true;
                }
            }
        }
        return dp[n-1];
    }
};