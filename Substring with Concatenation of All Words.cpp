class Solution {
public:
    // map<word, frequency>
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ret;
        if(S.size() == 0 || L.size() == 0) return ret;
        
        map<string, int> m;
        for(string str : L) m[str]++;
        
        int word_num = L.size();
        int word_len = L[0].size();
        for(int i = 0; i + word_len * word_num <= S.size(); ++i){
            
            map<string, int> tmp_m = m;
            bool flag = true;
            for(int j = i; j < i + word_len * word_num; j += word_len){
                string tmp_str = S.substr(j, word_len);
                tmp_m[tmp_str]--;
                if(tmp_m[tmp_str] < 0) { flag = false; break; }
            }
            for(auto it = tmp_m.begin(); it != tmp_m.end(); ++it){
                if(it->second > 0){
                    flag = false; break;
                }
            }
            if(flag) ret.push_back(i);
        }
        return ret;
    }
};