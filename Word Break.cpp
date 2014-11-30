class Solution {
public:
    // 1d dp, dp[i] can be segmented or not
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size();
        if(n == 0) return true;
        vector<bool> can_break (n, false);
        
        for(int start = 0; start < n; ++start){
            if(start > 0 && !can_break[start-1]) continue;
            for(int len = 1; start + len <= n; ++len){
                string str = s.substr(start, len);
                if(dict.find(str) != dict.end()){
                    can_break[start+len-1] = true;
                }
            }
        }
        return can_break[n-1];
    }
};