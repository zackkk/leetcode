class Solution {
public:
    // stack
    int longestValidParentheses(string s) {
        int maxlen = 0;
        stack<int> stk; // save '(' index
        int lastValidEnd = -1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                stk.push(i);
            }
            else{
                if(stk.empty()){ // no valid matching
                    lastValidEnd = i;
                }
                else{
                    stk.pop();   // matched
                    if(!st.empty())
                        maxlen = max(maxlen, i - stk.top());             // keep matching, "(()"
                    else
                        maxlen = max(maxlen, i - lastValidEnd);          // match the last one, ")()"
                }
            }
        }
        return maxlen; 
    }
};