class Solution {
public:
    // "window": [slow & fast]
    // move fast until repeat happens: [a b c d e f b] ...
    // move slow to get rid of repeat: a b [c d e f b ...] ---> continue to move fast
    // how to prove the correctness? IDK!!!
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        int maxLen = INT_MIN;
        unordered_set<char> myset;
        int slow = 0;
        int fast = 0;
        while(fast < s.size()){
            
            // no repeating chars
            if(myset.find(s[fast]) == myset.end()){
                myset.insert(s[fast]);
            }
            // has repeating char
            else{
                maxLen = max(maxLen, fast - slow);
                while(s[slow] != s[fast]){
                    myset.erase(s[slow]);
                    slow++;
                }   
                slow++;
            }
            fast++;
        }
        maxLen = max(maxLen, fast - slow);
        return maxLen;
    }
};