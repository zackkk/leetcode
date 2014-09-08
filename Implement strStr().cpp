class Solution {
public:
    // KMP
    char *strStr(char *haystack, char *needle) {
        if(NULL == haystack || NULL == needle) return NULL;
        int hLen = strlen(haystack);
        int nLen = strlen(needle);
        if(hLen < nLen) return NULL;
        for(int i = 0; i + nLen <= hLen; i++){
            char *p = &haystack[i];
            int j = 0;
            for( ; j < nLen; j++){
                if(*p != needle[j])
                    break;
                p++;
            }
            if(j == nLen)
                return &haystack[i];
        }
        return NULL;
    }   
};