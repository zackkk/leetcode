class Solution {
public:
    // start from all positions to left & right 
    string longestPalindrome(string s) {
        string ret = "";
        for(int i = 0; i < s.size(); i++){
            string s1 = helper(s, i, i); // case: bab
            string s2 = helper(s, i, i+1); // case: bb
            ret = s1.size() > ret.size() ? s1 : ret; 
            ret = s2.size() > ret.size() ? s2 : ret;
        }
        return ret;
    }
    string helper(string s, int i, int j){
        if(s[i] != s[j]) return "";
        while(i - 1 >= 0 && j + 1 < s.size() && s[i-1] == s[j+1]){
            i--;
            j++;
        }
        return s.substr(i, j-i+1); // (position, length)
    }
};