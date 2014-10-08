class Solution {
public:
    // corner cases: spaces, sign, out of boundary
    int atoi(const char *str) {
        int i = 0;
        while(str[i] == ' ') i++; // corner case 1: spaces at the beginning
        bool flag = true;
        if(str[i] == '+' || str[i] == '-'){ // corner case 2: sign token
            if(str[i] == '-') flag = false;
            i++;
        }
        
        long long ret = 0;
        for(; i < strlen(str); i++){
            int tmp = str[i] - '0';
            if(tmp < 0 || tmp  > 9) // corner case 3: non-numberic value
                break;
            ret = ret * 10 + tmp;
        }
        ret = flag ? ret : -ret;
        if(ret < INT_MIN || ret > INT_MAX){ // corner case 4: out of boundary
            if(flag) return INT_MAX;
            else return INT_MIN;
        }
        return (int)ret;
    }
};