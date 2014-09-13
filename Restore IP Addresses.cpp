class Solution {
public:
    // dfs
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        if(s.size() < 4 || s.size() > 12) return ret;
        dfs(ret, s, "", 0, 0);
        return ret;
    }
    void dfs(vector<string> &ret, string &s, string str, int count, int cur){
        if(count == 3 && cur < s.size()){
            int len = s.size()-cur;
            if(isValid(s.substr(cur, len))){
                str += s.substr(cur, len);
                ret.push_back(str);
            }
            return;
        }
        for(int len = 1; len <= 3; len++){
            if(cur+len <= s.size() && isValid(s.substr(cur, len))){
                dfs(ret, s, str+s.substr(cur, len)+".", count+1, cur+len);
            }
        }
    }
    bool isValid(string str){
        // "01"
        if(str[0] == '0') return str == "0";
        return (0 <= stoi(str)) && (stoi(str) <= 255);
    }
    
};