class Solution {
public:
     // Lucy Can't Drink Milk
    int romanToInt(string s) {
        map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        int ret = 0;
        int i = 0;
        while(i < s.size()){
            if(i + 1 < s.size() &&
                  ((s[i] == 'I' && s[i+1] == 'V') ||
                   (s[i] == 'I' && s[i+1] == 'X') ||
                   (s[i] == 'X' && s[i+1] == 'L') ||
                   (s[i] == 'X' && s[i+1] == 'C') ||
                   (s[i] == 'C' && s[i+1] == 'D') ||
                   (s[i] == 'C' && s[i+1] == 'M')) ){
                       
                    ret += m[s[i+1]] - m[s[i]];
                    i += 2;
                   
            }
            else{
                ret += m[s[i]];
                i++;
            }
        }
        return ret;
    }
};