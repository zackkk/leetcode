class Solution {
public:
    // straight-forward implementation, compare all strings with the first string
    string longestCommonPrefix(vector<string> &strs) {
        string ret = "";
        if(strs.size() == 0) return ret;
        for(int j = 0; j < strs[0].size(); j++){
            for(int i = 1; i < strs.size(); i++){
                if(strs[i][j] != strs[0][j])
                    return ret;
            }
            ret += strs[0][j];
        }
        return ret;
    }
};