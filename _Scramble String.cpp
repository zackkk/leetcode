class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        if(s1 == s2) return true;
        
        string t1 = s1;
        string t2 = s2;
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        if(t1 != t2) return false;
        
        for(int len = 1; len < s1.size(); ++len){
            string s11 = s1.substr(0, len);
            string s12 = s1.substr(len);
            string s21 = s2.substr(0, len);
            string s22 = s2.substr(len);
            
            if(isScramble(s11, s21) && isScramble(s12, s22)) return true;
            
            s21 = s2.substr(s1.size() - len);
            s22 = s2.substr(0, s1.size() - len);
            
            if(isScramble(s11, s21) && isScramble(s12, s22)) return true;
        }
        
        return false;
    }
};