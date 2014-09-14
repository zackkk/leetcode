class Solution {
public:
    // map<word, frequency>
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ret;
        if(L.size() == 0)
            return ret;
        
        map<string, int> m;
        for(int i = 0; i < L.size(); i++){ m[L[i]]++; } // default value: 0

        int wordLen = L[0].size();
        int wordNum = L.size();
		
        for(int i = 0; i + wordNum * wordLen <= S.size(); i++){ // i <= S.size() - wordNum * wordLen will overflow
            map<string, int> tmp_map;
			int j = 0;
        
            for(; j < wordNum; j++){
				string tmp_word = S.substr(i+j*wordLen, wordLen); // (position, length)
				if(!m[tmp_word]) { break; }
                tmp_map[tmp_word]++;
                if (tmp_map[tmp_word] > m[tmp_word]) { break;}
            }
            if(j  == wordNum)
                ret.push_back(i);
        }
        return ret;
    }
};