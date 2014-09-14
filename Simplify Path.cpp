class Solution {
public:
    // stringstream ss(path); ---> not working
    string simplifyPath(string path) {
        stack<string> st;
        for(int i = 0; i < path.size(); i++){
            if(path[i] == '/'){
                // multiple slashs
                while(i+1 < path.size() && path[i+1] == '/') { // corner case
                    i++;
                }
            }
            else{
                int indexLeft = i;
                int indexRight = i;
                while(indexRight+1 < path.size() && path[indexRight+1] != '/'){
                    indexRight++;
                    i++;
                }
                string token = path.substr(indexLeft, indexRight-indexLeft+1);
                if(token == ".") 
                    ;
                else if(token == ".."){ 
                    if(!st.empty()){ // corner case
                        st.pop();
                    }
                }
                else{
                    st.push(token);
                }
            }
        }
        
        string ret = st.empty() ?  "/" : "";
        while(!st.empty()){
            string token = st.top();
            st.pop();
            ret = "/" + token + ret;
        }
        return ret;
    }
};