class Solution {
public:
    // dfs, 8-queens transformation
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> ret;
        vector<int> cur;
        dfs(ret, cur, num);
        return ret;
    }
    void dfs(vector<vector<int>> &ret, vector<int> cur, vector<int> &num){
        if(cur.size() == num.size()){
            ret.push_back(cur);
            return;
        }
        for(int i = 0; i < num.size(); i++){
            if(find(cur.begin(), cur.end(), num[i]) == cur.end()){
                cur.push_back(num[i]);
                dfs(ret, cur, num);
                cur.pop_back(); 
            }
        }
    }
};