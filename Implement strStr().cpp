class Solution {
public:
    // KMP
    char *strStr(char *haystack, char *needle) {
        if(haystack == NULL || needle == NULL){
            return NULL;
        }
        int hLen = strlen(haystack);
        int nLen = strlen(needle);
        if(hLen < nLen) return NULL;
        for(int i = 0; i + nLen - 1 < hLen; i++){
            char *p = &haystack[i];
            int j = 0;
            while(j < nLen){
                if(*p != needle[j])
                    break;
                p++;
                j++;
            }
            if(j == nLen)
                return &haystack[i];
        }
        return NULL;
    }   
};