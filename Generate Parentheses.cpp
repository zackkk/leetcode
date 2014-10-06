class Solution {
public:
    // dfs, cc150
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        helper(n, 0, 0, "", ret);
        return ret;
    }
    void helper(int n, int left, int right, string str, vector<string> &ret){
        if(left == n && right == n){
            ret.push_back(str);
            return;
        }
        if(left < n)
            helper(n, left+1, right, str+"(", ret);   // left++ and ++left didn't work
        if(right < left)
            helper(n, left, right+1, str+")", ret);
    }
};