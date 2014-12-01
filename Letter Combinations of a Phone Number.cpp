class Solution {
public:
    vector<string> letterCombinations(string digits) {
    
        map<char, string> m;
        m['1'] = "";
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
    
        vector<string> ret;
        ret.push_back("");
        
        for(int i = 0; i < digits.size(); ++i){
            string str = m[digits[i]];
            
            vector<string> tmp = ret;
            ret.clear();
            for(int j = 0; j < str.size(); ++j){
                for(string s : tmp){ // for each string, append one letter
                    s += str[j];
                    ret.push_back(s);
                }    
            }
        }
        return ret;
    }
};