class Solution {
public:
    // '*' is different from Regular Expression Matching
    // failed in large data set... other solutions are confusing...
    bool isMatch(const char *s, const char *p) {
        if(*p == '*'){
            while(*p == '*') p++; // continous '*'
            if(*p == '\0') return true;
            while(*s != '\0' && !isMatch(s, p))
                s++;
            return *s == '\0' ? false : true; // since p has not reached end
        }
        else if(*s == '\0' && *p == '\0') return true;
        else if(*p == *s || *p == '?') return isMatch(++s, ++p);
        else return false;
    }
};