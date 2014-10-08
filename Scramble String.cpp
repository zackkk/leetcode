class Solution {
public:
    // 3d dp ---> fucked up ---> recursion
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size())  return false;
        if(s1 == s2) return true;
        
        string sorteds1 = s1;
        string sorteds2 = s2;
        sort(sorteds1.begin(), sorteds1.end());
        sort(sorteds2.begin(), sorteds2.end());
        if(sorteds1 != sorteds2) return false;
        
        // decompose s1 & s2
        for(int i = 1; i < s1.size(); i++){
            string s11 = s1.substr(0, i);
            string s12 = s1.substr(i);
            string s21 = s2.substr(0, i);
            string s22 = s2.substr(i);
            
            if(isScramble(s11, s21) && isScramble(s12, s22)) return true;
            
            s21 = s2.substr(s2.size()-i);
            s22 = s2.substr(0, s2.size()-i);

            if(isScramble(s11, s21) && isScramble(s12, s22)) return true;
        }
        
        return false;
    }
};