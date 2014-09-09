class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string ret = "";
        if(strs.size() == 0) return ret;
        for(int j = 0; j < strs[0].size(); j++){
            char c = strs[0][j];
            for(int i = 1; i < strs.size(); i++){
                if(strs[i][j] != c)
                    return ret;
            }
            ret += c;
        }
        return ret;
    }
};