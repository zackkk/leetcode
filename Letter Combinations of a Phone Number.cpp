class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> myMap;
        myMap['1'] = "";
        myMap['2'] = "abc";
        myMap['3'] = "def";
        myMap['4'] = "ghi";
        myMap['5'] = "jkl";
        myMap['6'] = "mno";
        myMap['7'] = "pqrs";
        myMap['8'] = "tuv";
        myMap['9'] = "wxyz";
    
        vector<string> prev;
        prev.push_back(""); // point
        
        // all digits
        for(int i = 0; i < digits.size(); i++){
            // add to the previous vector
            string str = myMap[digits[i]];
            vector<string> cur;
            // all letters
            for(int j = 0; j < str.size(); j++){
                for(int k = 0; k < prev.size(); k++){
                    cur.push_back(prev[k] + str[j]);   
                }
            }
            prev = cur;
        }
        return prev;
    }
};