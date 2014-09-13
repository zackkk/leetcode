class Solution {
public:
    // dfs, transfer to Permutations 1
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end()); // key
        vector<vector<int>> ret;
        vector<int> vec;
        vector<bool> visited (num.size(), false);
        dfs(ret, vec, num, visited);
        return ret;
    }
    void dfs(vector<vector<int>> &ret, vector<int> vec, vector<int> &num, vector<bool> visited){
        if(num.size() == vec.size()){
            ret.push_back(vec);
            return;
        }
        for(int i = 0; i < num.size(); i++){
            if(visited[i] || (i > 0 && num[i-1] == num[i] && visited[i-1] == false)) // key
                continue;
            visited[i] = true;
            vec.push_back(num[i]);
            dfs(ret, vec, num, visited);
            vec.pop_back();
            visited[i] = false;
        }
    }
};