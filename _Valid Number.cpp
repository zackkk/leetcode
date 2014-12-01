class Solution {
public:
    // endless corner cases,  [+/-] d.d (E/e)[+/-]d
    bool isNumber(const char *s) {
        while(*s == ' ') s++;
        
        if(*s == '+' || *s == '-') s++;
        
        int count_num = 0;
        int count_pt  = 0;
        while((*s >= '0' && *s <= '9') || (*s == '.')){
            *s == '.' ? count_pt++ : count_num++;
            s++;
        }
        if(count_pt > 1 || count_num == 0) return false; // at most one point
        
        if(*s == 'e'){
            s++;
            if(*s == '+' || *s == '-') s++;
            
            count_num = 0;
            while(*s >= '0' && *s <= '9'){
                count_num++;
                s++;
            }
            if(count_num == 0) return false;
        }
        
        while(*s == ' ') s++;
        return *s == '\0';
    }
};