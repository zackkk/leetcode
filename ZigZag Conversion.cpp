class Solution {
public:
    // key: increase then update increase flag
    string convert(string s, int nRows) {
        if(nRows <= 1) return s;
        vector<string> strs (nRows, "");
        
        bool flag = true;
        int index = -1;
        for(int i = 0; i < s.size(); ++i){
            index = flag ? index+1 : index-1;
            strs[index] += s[i];
            
            if(index == nRows - 1) flag = false;
            else if(index == 0) flag = true;
        }
        
        string ret = "";
        for(string str : strs) ret += str;
        return ret;
    }
};