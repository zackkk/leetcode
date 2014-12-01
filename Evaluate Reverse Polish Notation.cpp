class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if(tokens.size() == 0) return 0;
        stack<string> stk;
        for(string token : tokens){
            if(!isOperator(token))
                stk.push(token);
            else{
                int num1 = stoi(stk.top());
                stk.pop();
                int num2 = stoi(stk.top());
                stk.pop();
                if(token == "+") stk.push(to_string(num2 + num1));
                if(token == "-") stk.push(to_string(num2 - num1));
                if(token == "*") stk.push(to_string(num2 * num1));
                if(token == "/") stk.push(to_string(num2 / num1));
            }
        }
        return stoi(stk.top());
    }
    
    bool isOperator(string str){
        return (str == "+" || str == "-" || str == "*" || str == "/"); 
    }
};