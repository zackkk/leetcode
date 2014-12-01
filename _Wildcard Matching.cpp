class Solution {
public:
    // magic
    bool isMatch(const char *s, const char *p) {
        const char *star_s = NULL; // store the position of the last "*"
        const char *star_p = NULL; // store the mapping position of the last "*" in s
        
        while(*s){
            
            if(*p == *s || *p == '?'){
                p++;
                s++;
                continue;
            }
            
            // "*" match zero char, save its position
            if(*p == '*'){
                star_p = p;
                star_s = s;
                p++;
                continue;
            }
            
            // "*" match one/more chars
            if(star_p){
                p = star_p + 1;
                star_s++;
                s = star_s;
                continue;
            }
            
            return false;
        }
        while(*p == '*') p++;
        return *p == '\0';
    }
};