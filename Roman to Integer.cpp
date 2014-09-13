class Solution {
public:
    int romanToInt(string s) {
        map<char,int> myMap;
        myMap['I'] = 1;
        myMap['V'] = 5;
        myMap['X'] = 10;
        // Lucy Can't Drink Milk
        myMap['L'] = 50;
        myMap['C'] = 100;
        myMap['D'] = 500;
        myMap['M'] = 1000;
        
        int ret = 0;
        for(int i = 0; i < s.length(); i++){
            if(i+1 < s.length() && ((s[i] == 'I' && s[i+1] == 'V') ||
                                    (s[i] == 'I' && s[i+1] == 'X') || 
                                    (s[i] == 'X' && s[i+1] == 'L') || 
                                    (s[i] == 'X' && s[i+1] == 'C') || 
                                    (s[i] == 'C' && s[i+1] == 'D') || 
                                    (s[i] == 'C' && s[i+1] == 'M'))
              ){
                ret += (myMap[s[i+1]] - myMap[s[i]]);
                i++;
            }
            else{
                ret += myMap[s[i]];
            }
        }
        return ret;
    }
};