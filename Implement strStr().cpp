class Solution {
public:
    // KMP, return substring pointer if existed in C
    char *strStr(char *haystack, char *needle) {
        if(haystack == NULL || needle == NULL){
            return NULL;
        }
        int hLen = strlen(haystack);
        int nLen = strlen(needle);
        if(hLen < nLen) return NULL;
        int i,j;
        for(i = 0; i + nLen - 1 < hLen; i++){
            for(j = 0; j < nLen; j++){
                if(haystack[i+j] != needle[j])
                break;
            }
            if(j == nLen)
                return &haystack[i];
        }
        return NULL;
    }   
};