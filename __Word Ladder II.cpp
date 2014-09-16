class Solution {
public:
    // dfs: Time Limit Exceeded. 
    // bfs+backtracking: fucked up
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string>> ret;
        vector<string> ladder;
        ladder.push_back(start);
        set<string> visited; // avoid duplicate ladders
        visited.insert(start);
		int min = INT_MAX;
        helper(start, end, dict, ret, visited, ladder, min);
        return ret;
    }
    void helper(string start, string end, unordered_set<string> &dict, vector<vector<string>> &ret, set<string> &visited, vector<string> ladder, int &min){
        if(start == end){
            if(ladder.size() == min){
                ladder.push_back(end);
                ret.push_back(ladder);
            }
            if(ladder.size() < min){ // update min level, which is time consuming
                ret.clear();
                ladder.push_back(end);
                ret.push_back(ladder);
				min = ladder.size();
            }
            return;
        }
    
        for(int i = 0; i < start.size(); i++){
            char ori = start[i];
            for(char c = 'a'; c <= 'z'; c++){
                start[i] = c;
                if(dict.find(start) != dict.end() && visited.find(start) == visited.end()){
                    visited.insert(start);
                    ladder.push_back(start);
                    helper(start, end, dict, ret, visited, ladder, min);
                    ladder.pop_back();
                    visited.erase(start);
                }
            }
            start[i] = ori;
        }  
    }
};