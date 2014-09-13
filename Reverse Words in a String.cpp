class Solution {
public:
    // iterate from end to start
    void reverseWords(string &s) {
        string ret;
        int i = s.size() - 1;
        while(i >= 0){
            // spaces
            while(i >= 0 && s[i] == ' ') i--;
            if(i < 0) break;
            
            // if it is at the beginning
            if(!ret.empty()) ret += ' ';
            
            // get the word
            string tmp;
            while(i >= 0 && s[i] != ' ') { tmp += s[i]; i--; }
            reverse(tmp.begin(), tmp.end()); //  point
            
            ret += tmp;
        }
        s = ret;
    }
};