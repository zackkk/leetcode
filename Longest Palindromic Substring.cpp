class Solution {
public:
    // start from all positions to left & right 
    string longestPalindrome(string s) {
        int n = s.size();
        if(n <= 1) return s;
        
        string max_str = "";
        
        for(int i = 0; i < n-1; ++i){
            string str1 = getPalindrome(s, i, i);
            string str2 = getPalindrome(s, i, i+1);
            max_str = str1.size() > max_str.size() ? str1 : max_str;
            max_str = str2.size() > max_str.size() ? str2 : max_str;
        }
        return max_str;
    }
    
    string getPalindrome(string &s, int i, int j){
        if(s[i] != s[j]) return ""; 
        
        while(i - 1 >= 0 && j + 1 < s.size() && s[i-1] == s[j+1]){
            i--;
            j++;
        }
        return s.substr(i, j-i+1); // point: use string index, avoid string operation 
    }
};