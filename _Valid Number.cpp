class Solution {
public:
    // hard
    // 1. regular expression 2. Finate Autumata Machine: http://blog.csdn.net/kenden23/article/details/18696083
    // [+/-] d.d (E/e)[+/-]d
    bool isNumber(const char *s) {
        int i = 0;
        
        // remove spaces
        while(i < strlen(s) && s[i] == ' ') i++;
        if(i == strlen(s)) return false;
        int j = strlen(s)-1;
        while(j >= 0 && s[j] == ' ') j--;
        if(j < 0) return false;
        
        if(s[i] == '+' || s[i] == '-') i++;
        
        bool num = false;
        bool dot = false;
        bool exp = false;
        while(i <= j){
            if(s[i] >= '0' && s[i] <= '9') 
                num = true;
            else if(s[i] == '.'){
                if(exp) return false;
                if(dot) return false;
                dot = true;
            }
            else if(s[i] == 'e'){
                if(exp) return false;
                if(!num) return false;
                exp = true;
                num = false;
            }
            else if(s[i] == '+' || s[i] == '-'){
                if(s[i-1] != 'E' && s[i-1] != 'e') return false;
            }
            else 
                return false;
            i++;
        }
        return num;
    }
};