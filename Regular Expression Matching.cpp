class Solution {
public:
    // case 1: '*'
    // case 2: no '*'
    bool isMatch(const char *s, const char *p) {
        return helper(s, p, 0 ,0);
    }
    bool helper(const char *s, const char *p, int i, int j){
        if(j == strlen(p)) return i == strlen(s);
        
        //case 1: "*"
        if(j + 1 < strlen(p) && p[j+1] == '*'){
            while(i < strlen(s) && (p[j] == s[i] || p[j] == '.')){  // '*' matches 0, 1, 2, 3, times...
                if(helper(s, p, i, j+2)) return true; // multiple cases
                i++;
            }
            return helper(s, p, i, j+2); // no matches, move on
        }
        //case 2: no "*"
        else{
            if(i < strlen(s) && (p[j] == s[i] || p[j] == '.'))
                return helper(s, p, i+1, j+1);
            else
                return false;
        }
    }
};