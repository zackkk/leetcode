class Solution {
public:
    // dfs ---> 1d dp : http://changhaz.wordpress.com/2014/04/30/leetcode-word-break-ii/
    // save all "solutions" at position i, iterate from tail to head.
    
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        //vector<vector<string>> vv (s.size(), vector<string> (s.size(), ""));
        vector<vector<string>> vv;
        for(int i = 0; i < s.size(); i++){
            vector<string> tmp_vs;
            vv.push_back(tmp_vs);
        }

        // tip: string malipulation: from back to end, easier to get a string
        for(int i = s.size()-1; i >= 0; i--){
            for(int j = i; j < s.size(); j++){
                string tmp_str = s.substr(i, j-i+1);
                if(dict.find(tmp_str) != dict.end()){
                    vector<string> vec;
                    if(j == s.size()-1){
                        vec.push_back(tmp_str);
                    }
                    else{
						vec = vv[j+1];
						for(int i = 0; i < vec.size(); i++)
							vec[i] = tmp_str + " " + vec[i];
                    }
					vector<string> vvi = vv[i];
					vvi.insert(vvi.end(), vec.begin(), vec.end());
                    vv[i] = vvi;
                }
            }
        }
		return vv[0];
    }
};