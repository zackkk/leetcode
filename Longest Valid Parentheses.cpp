class Solution {
public:
    // stack
    int longestValidParentheses(string s) {
        int max_len = 0;
        int last_close = -1;
        stack<int> stk;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '(') stk.push(i);
            else{ // try to match
                if(stk.empty()) last_close = i; // no match
                else{
                    stk.pop();
                    if(!stk.empty()) 
                        max_len = max(max_len, i - stk.top());
                    else
                        max_len = max(max_len, i - last_close);
                }
            }
        }
        return max_len;
    }
};