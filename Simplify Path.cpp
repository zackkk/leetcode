class Solution {
public:
    // corner cases: multiple slashs, empty stack
    string simplifyPath(string path) {
        stack<string> stk;
        for(int i = 0; i < path.size(); i++){
            if(path[i] == '/'){
                // multiple slashs
                while(i+1 < path.size() && path[i+1] == '/') { // corner case
                    i++;
                }
            }
            else{
                // get the token
                int indexLeft = i;
                int indexRight = i;
                while(indexRight+1 < path.size() && path[indexRight+1] != '/'){
                    indexRight++;
                    i++;
                }
                string token = path.substr(indexLeft, indexRight-indexLeft+1);
                
                // parse the token
                if(token == ".") 
                    ;
                else if(token == ".."){ 
                    if(!stk.empty()){ // corner case
                        stk.pop();
                    }
                }
                else{
                    stk.push(token);
                }
            }
        }
        
        string ret = stk.empty() ?  "/" : "";
        while(!stk.empty()){
            string token = stk.top();
            stk.pop();
            ret = "/" + token + ret;
        }
        return ret;
    }
};