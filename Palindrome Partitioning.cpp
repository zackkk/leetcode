class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        if(s.size() == 0) return ret;
        vector<string> v;
        dfs(s, ret, v, 0);
        return ret;
    }
    
    void dfs(string s, vector<vector<string>> &ret, vector<string> &v, int cur){
        if(cur == s.size()){
            ret.push_back(v);
            return;
        }
        
        for(int i = cur; i < s.size(); ++i){
            string tmp = s.substr(cur, i-cur+1);
            if(isPalindrome(tmp)){
                v.push_back(tmp);
                dfs(s, ret, v, i+1);
                v.pop_back();
            }
        }
    }
    
    bool isPalindrome(string &s){
        int i = 0;
        int j = s.size() - 1;  // error if put in the "for"
        for( ; i < j; ++i, --j){
            if(s[i] != s[j]) return false;
        }
        return true;
    }
};