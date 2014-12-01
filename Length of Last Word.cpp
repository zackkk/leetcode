class Solution {
public:
    // use s[i]
    int lengthOfLastWord(const char *s) {
        if(s == NULL) return 0;
        int right = strlen(s) - 1;
        while(s[right] == ' ') right--;
        if(right < 0) return 0;
        
        int left = right;
        while(left - 1 >= 0 && s[left-1] != ' ') left--;
        return right - left + 1;
    }
};