class Solution {
public:
    // bfs + dfs, use a map to save fathers in bfs, then use dfs to do back tracking
    // use build-in funcs: swap, reverse. use keyword: auto
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string>> ret;
        if(start == end) return ret;
        unordered_set<string> current;
        unordered_set<string> next;
        unordered_set<string> visited;
        map<string, vector<string>> fathers;
        
        current.insert(start);
        bool found = false;
        while(!current.empty() && !found){
            
            for(string str : current)
                visited.insert(str);
            
            for(string str : current){
                for(int i = 0; i < str.size(); i++){
                    for(char j = 'a'; j <= 'z'; j++){
                        if(j == str[i]) continue;
                        string tmp = str;
                        tmp[i] = j;
                        if(tmp == end) found = true;
                        if(dict.find(tmp) != dict.end() && visited.find(tmp) == visited.end()){
                            next.insert(tmp);
                            fathers[tmp].push_back(str);
                        }
                    }
                }
            }
            current.clear();
            swap(current, next);
            //current = next;  it got Time Limit Exceeded
        }
        
        if(found){
            vector<string> vec;
            dfs(start, end, vec, fathers, ret);
        }
    }
    
    void dfs(string &start, string &now, vector<string> &vec, map<string, vector<string>> &fathers, vector<vector<string>> &ret){
        vec.push_back(now);
        
        if(now == start){
            //reverse(vec.begin(), vec.end()); bug happened here, can't reverse since it would mess up its original order
            ret.push_back(vec);
            reverse(ret.back().begin(), ret.back().end());
            vec.pop_back();
            return;
        }
        vector<string> strs = fathers.find(now)->second;
        for(string str : strs)
            dfs(start, str, vec, fathers, ret);
        
        vec.pop_back();
    }
};