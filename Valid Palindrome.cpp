class Solution {
public:
    // straight-forward implementation
    bool isPalindrome(string s) {
        if(s.size() == 0) return true;
        int left  = 0;
        int right = s.size() - 1;
        while(left < right){
            while(left < right && !isAlphanumeric(s[left])) left++;
            while(left < right && !isAlphanumeric(s[right])) right--;
            if(s[left] != s[right] && abs(s[left] - s[right]) != abs('a' - 'A'))
                return false;
            left++;
            right--;
        }
        return true;
    }
    bool isAlphanumeric(char c){
        if(('0' <= c && c <= '9') ||
           ('a' <= c && c <= 'z') ||
           ('A' <= c && c <= 'Z'))
            return true;
        else
            return false;
    }
};