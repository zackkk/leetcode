class Solution {
public:
    int longestValidParentheses(string s) {
        int ret = 0;
        // save '(' index
        stack<int> st;
        int lastValidEnd = -1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(i);
            }
            else{
                if(st.empty()){ // no valid matching
                    lastValidEnd = i;
                }
                else{
                    st.pop();
                    if(!st.empty()){ ret = max(ret, i - st.top()); } // keep matching, "(()"
                    else{ ret = max(ret, i - lastValidEnd); }        // match the last one, ")()"
                }
            }
        }
        return ret; 
    }
};