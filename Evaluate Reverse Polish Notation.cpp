class Solution {
public:
    // stack
    int evalRPN(vector<string> &tokens) {
        if(tokens.size() == 0) return 0;
        stack<string> stk;
        for(int i = 0; i < tokens.size(); i++){
            if(!isOperator(tokens[i])){
                stk.push(tokens[i]);
            }
            else{
                string num1 = stk.top(); 
                stk.pop();
                string num2 = stk.top();
                stk.pop();
                string sum = "";
                if (tokens[i] == "+")
                    sum += to_string(stoi(num2) + stoi(num1));
                else if (tokens[i] == "-")
                    sum += to_string(stoi(num2) - stoi(num1));
                else if (tokens[i] == "*")
                    sum += to_string(stoi(num2) * stoi(num1));
                else
                    sum += to_string(stoi(num2) / stoi(num1));
                stk.push(sum);
            }
        }
        string sum = stk.top();
        stk.pop();
        return stoi(sum);
    }
    
    bool isOperator(string s){
        return (s == "+" || s == "-" || s == "*" || s == "/");
    }
};