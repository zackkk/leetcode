class Solution {
public:
    // start from each position
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
        while(i >= 0 && j < s.size() && s[i] == s[j]){
            i--;
            j++;
        }
        i++;
        j--;
        if(j >= i) return s.substr(i, j-i+1); // (position, length)
        return "";
    }
};