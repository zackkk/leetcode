class Solution {
public:
    // dfs
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        if(s.size() == 0) return ret;
        vector<string> vec;
        dfs(ret, vec, s, 0);
        return ret;
    }
    
    void dfs(vector<vector<string>> &ret, vector<string> vec, string s, int start){
        if(start == s.size()){ 
            ret.push_back(vec);
            return;
        }
        for(int i = start; i < s.size(); i++){
            if(isPalindrome(start, i, s)){
                vec.push_back(s.substr(start, i-start+1));
                dfs(ret, vec, s, i+1);
                vec.pop_back();
            }
        }
    }
    
    bool isPalindrome(int start, int end, string str){
        while(start < end){
            if(str[start] != str[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};