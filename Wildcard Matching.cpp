class Solution {
public:
    // two "star" pointers for going back to match, "*" matches zero times at the beginning
    bool isMatch(const char *s, const char *p) {
        const char *star_p = NULL; // store the position of the last "*"
        const char *star_p_s = s; // store the mapping position of the last "*" in s
        
        while(*s){
            // normal case
            if(*p == '?' || *p == *s){
                p++;
                s++;
                continue;
            }
            
            // one "star" in p can match everything, so we save only the most recent "star"
            if(*p == '*'){
                star_p = p; 
                star_p_s = s;
                p++;
                continue;
            }
            
            // can't move on, go back to use "*", to match one/more times
            if(star_p){
                p = star_p + 1;
                star_p_s++;
                s = star_p_s;
                continue;
            }
            
            // no matching 
            return false;
        } 
        
        while(*p == '*') p++; // "******..." equals "*"
        return !*p; // check if p has reached to end
    }
};