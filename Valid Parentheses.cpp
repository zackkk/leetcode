class Solution {
public:
    // stack
    bool isValid(string s) {
        stack<char> stk;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                stk.push(s[i]);
            else{
                if(stk.empty()) return false;
                char tmp = stk.top();
                stk.pop();
                if(s[i] == ')' && tmp != '(') return false;
                if(s[i] == ']' && tmp != '[') return false;
                if(s[i] == '}' && tmp != '{') return false;
            } 
        }
        return stk.empty();
    }
};