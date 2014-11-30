class Solution {
public:
    // from head to tail -> Memory Limit Exceeded
    // 1d dp, from tail to head , save all "solutions" at position i
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<vector<string>> vv (s.size(), vector<string> ());
        
        // tip: string malipulation: from back to end, easier to get a string
        for(int i = s.size()-1; i >= 0; i--){
            for(int j = i; j < s.size(); j++){
                string tmp = s.substr(i, j-i+1);
                if(dict.find(tmp) != dict.end()){
                    
                    vector<string> vec;
                    if(j == s.size()-1){
                        vec.push_back(tmp);
                    }
                    else{
                        // if vv[j+1] is empty, then nothing will be inserted into vv[i]
                        vec = vv[j+1];
                        for(int k = 0; k < vec.size(); k++)
                            vec[k] = tmp + " " + vec[k];
                    }
                    vv[i].insert(vv[i].end(), vec.begin(), vec.end()); // add one more solution at the tail
                }
            }
        }
        return vv[0];
    }
};