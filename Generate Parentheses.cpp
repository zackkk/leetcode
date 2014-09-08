class Solution {
public:
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
            // left++ and ++left didn't work
            helper(n, left+1, right, str+"(", ret);
        if(right < left)
            helper(n, left, right+1, str+")", ret);
    }
};