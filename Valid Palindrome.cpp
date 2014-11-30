class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        if(n == 0) return true;
        
        int i = 0;
        int j = n-1;
        while(i < j){
            while(i < j && !isAlphanumeric(s[i])) i++;
            while(i < j && !isAlphanumeric(s[j])) j--;
            if(i < j && s[i] != s[j] && abs(s[i] - s[j]) != abs('a' - 'A'))
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    bool isAlphanumeric(char c){
        return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9');
    }
};