class Solution {
public:
    // hard: consider corner cases
    // 1. regular expression 2. Finate Autumata Machine: http://blog.csdn.net/kenden23/article/details/18696083
    // [+/-] d.d (E/e)[+/-]d
    bool isNumber(const char *s) {
        int i = 0;
        int j = strlen(s)-1;
        
        // remove spaces
        while(i < strlen(s) && s[i] == ' ') i++;
        while(j >= 0 && s[j] == ' ') j--;
        if(i == strlen(s) || j < 0) return false;
        
        if(s[i] == '+' || s[i] == '-') i++;
        
        bool num = false;
        bool dot = false;
        bool exp = false; // exponential
        
        while(i <= j){
            if(s[i] >= '0' && s[i] <= '9') 
                num = true;
            else if(s[i] == '.'){
                if(dot) return false; // can't repeat
                if(exp) return false; // exp can't appear before
                dot = true;
            }
            else if(s[i] == 'e'){
                if(exp) return false; // can't repeat
                if(!num) return false; // num must appear before
                exp = true;
                num = false; // num must appear later
            }
            else if(s[i] == '+' || s[i] == '-'){ // '+'/'-' must be followed with 'E'/'e'
                if(s[i-1] != 'E' && s[i-1] != 'e') 
                    return false;
            }
            else 
                return false;
            i++;
        }
        return num; // end with number
    }
};