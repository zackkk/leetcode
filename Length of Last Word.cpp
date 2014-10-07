class Solution {
public:
    // straight-forward implementation
    int lengthOfLastWord(const char *s) {
        if(strlen(s) == 0) return 0;
        int right = strlen(s) - 1;
        while(s[right] == ' '){ right--; }
        if(right < 0) return 0; // all spaces
        
        int left = right;
        while(left - 1 >= 0 && s[left-1] != ' '){
            left--;
        }
        return right - left + 1;
    }
};