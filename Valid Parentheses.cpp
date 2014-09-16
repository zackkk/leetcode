class Solution {
public:
    // stack
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else{
                if(st.empty())
                    return false;
                char tmp = st.top();
                st.pop();
                if(s[i] == ')' && tmp != '(')
                    return false;
                if(s[i] == '}' && tmp != '{')
                    return false;
                if(s[i] == ']' && tmp != '[')
                    return false;
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};