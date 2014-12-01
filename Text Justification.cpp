class Solution {
public:
    // concise :)
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> ret;
        int n = words.size();
        if(n == 0 || L == 0) { ret.push_back(""); return ret; }
        
        int i = 0;
        while(i < n){
           vector<string> ws;  // words of current line
           int ws_len = 0;
           while((i < n && ws.size() == 0) ||
                 (i < n && ws_len + ws.size() - 1 + words[i].size() + 1 <= L)){
                     ws.push_back(words[i]);
                     ws_len += words[i].size();
                     i++;
                 }
                 
            int space = L - ws_len;
            if(i == n || ws.size() == 1){ //special cases: last line / one word in a line
                for(int j = 0; j < ws.size() - 1 && space > 0; ++j, --space) ws[j] += " "; // bug: use "&&" !
                for( ; space > 0; --space) ws[ws.size()-1] += " ";
            }
            else{
                while(space > 0){
                    for(int j = 0; j < ws.size() - 1 && space > 0; ++j, --space) ws[j] += " ";
                }
            }
            
            string str;
            for(string tmp : ws) str += tmp;
            ret.push_back(str);
        }
        return ret;
    }
};