class Solution {
public:
    // corner cases: multiple slashs, empty stack
    string simplifyPath(string path) {
        vector<string> tokens;
        split(path, tokens);
        stack<string> stk;
        for(string token : tokens){
            if(token == ".") 
                continue;
            else if(token == ".."){
                if(!stk.empty())
                    stk.pop();
            }
            else
                stk.push(token);
        }
        
        string ret = "";
        while(!stk.empty()){
            string tmp = stk.top();
            stk.pop();
            ret = "/" + tmp + ret;
        }
        return ret == "" ? "/" : ret;
        
    }
    
    void split(string path, vector<string> &tokens){
        int i = 0;
        while(i < path.size()){
            while(i < path.size() && path[i] == '/') i++;
            int start = i;
            while(i < path.size() && path[i] != '/') i++;
            int end = i;
            if(end > start) tokens.push_back(path.substr(start, end - start));
        }
    }
};