class Solution {
public:
    // key: increase then update increase flag
    string convert(string s, int nRows) {
        if(nRows == 1) return s; // special case
        vector<string> rows (nRows, "");
       
        bool incFlag = true;
        int curRow = -1;
        
        for(int i = 0; i < s.size(); i++){
            curRow = incFlag ? curRow + 1 : curRow - 1;
            rows[curRow] += s[i];
            
            // update increase flag
            if(curRow == nRows - 1) 
                incFlag = false;
            else if(curRow == 0) 
                incFlag = true;
        }
        
        string ret;
        for(int i = 0; i < nRows; i++)
            ret += rows[i];
        return ret;
    }
};