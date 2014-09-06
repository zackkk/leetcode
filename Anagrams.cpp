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
        
        // map: iterator->first, iterator->second
        vector<string> ret;
        for(map<string, vector<string>>::iterator it = myMap.begin(); it != myMap.end(); ++it){
            vector<string> vec = it->second;
            if(vec.size() > 1){
                ret.insert(ret.end(), vec.begin(), vec.end());
            }
        }
        return ret;
    }
};