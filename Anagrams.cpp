class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string, vector<string>> m;
        
        for(string str : strs){
            string key = str;
            sort(key.begin(), key.end());
            m[key].push_back(str);
        }
        
        vector<string> ret;
        for(auto it = m.begin(); it != m.end(); ++it){
            if((it->second).size() > 1)
                ret.insert(ret.end(), it->second.begin(), it->second.end());
        }
        return ret;
    }
};