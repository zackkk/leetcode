class Solution {
public:
    // stack
    int evalRPN(vector<string> &tokens) {
        if(tokens.size() == 0) return 0;
        stack<string> st;
        for(int i = 0; i < tokens.size(); i++){
            if(!isOperator(tokens[i])){
                st.push(tokens[i]);
            }
            else{
                string num1 = st.top(); 
                st.pop();
                string num2 = st.top();
                st.pop();
                string sum = "";
                if (tokens[i] == "+")
                    sum += to_string(stoi(num2) + stoi(num1));
                else if (tokens[i] == "-")
                    sum += to_string(stoi(num2) - stoi(num1));
                else if (tokens[i] == "*")
                    sum += to_string(stoi(num2) * stoi(num1));
                else
                    sum += to_string(stoi(num2) / stoi(num1));
                st.push(sum);
            }
        }
        string sum = st.top();
        st.pop();
        return stoi(sum);
    }
    bool isOperator(string s){
        return (s == "+" || s == "-" || s == "*" || s == "/");
    }
};