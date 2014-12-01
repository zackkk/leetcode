class Solution {
public:
    // "window": [slow & fast]
    // move fast until repeat happens: [a b c d e f b] ...
    // move slow to get rid of repeat: a b [c d e f b ...] ---> continue to move fast
    // how to prove the correctness? IDK!!!
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> myset;
        int n = s.size();
        
        int slow = 0;
        int max_len = 0;
        for(int i = 0; i < n; ++i){
            if(myset.find(s[i]) == myset.end()){
                myset.insert(s[i]);
            }
            else{
                max_len = max(max_len, i - slow);
                while(s[slow] != s[i]){
                    myset.erase(s[slow]);
                    slow++;
                }
                slow++;
            }
        }
        max_len = max(max_len, n - slow);
        return max_len;
    }
};