class Solution {
public:
    // adjacency matrix
    vector<string> anagrams(vector<string> &strs) { 
        
        map<string, vector<string>> myMap;
        for(int i = 0; i < strs.size(); i++){
            string key = strs[i];
            sort(key.begin(), key.end());
            myMap[key].push_back(strs[i]);
        }
        
        // map: iterator->first, iterator->second; auto: map<string, vector<string>>::iterator
        vector<string> ret;
        for(auto it = myMap.begin(); it != myMap.end(); ++it){
            if(it->second.size() > 1){
                ret.insert(ret.end(), it->second.begin(), it->second.end());
            }
        }
        return ret;
    }
};