class Solution {
public:
    // KMP, return substring pointer if existed in C
    int strStr(char *haystack, char *needle) {
        int m = strlen(haystack);
        int n = strlen(needle);
        for(int i = 0; i <= m-n; ++i){
            int j = 0;
            for(; j < n; ++j){
                if(needle[j] != haystack[i+j]) break;
            }
            if(j == n) return i;
        }
        return -1;
    }
};