class Solution {
public:
    // corner cases: spaces, sign, out of boundary
    int atoi(const char *str) {
        int len = strlen(str);
        int i = 0;
        while(i < len && str[i] == ' ') i++;
        bool sign = true;
        if(i < len && ((str[i] == '+') || (str[i] == '-')) ){
            if(str[i] == '-') sign = false;
            i++;
        }
        
        long long ret = 0;
        while(i < len && str[i] >= '0' && str[i] <= '9'){
            ret = ret * 10 + (str[i] - '0');
            if(ret > INT_MAX){ 
                return sign ? INT_MAX : INT_MIN;
            }
            i++;
        }
        
        return sign ? ret : -ret;
    }
};