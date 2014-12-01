class Solution {
public:
    // two pointers, dynamicly maintain window frame that contains all chars in T
    string minWindow(string S, string T) {
        vector<int> vt (256, 0);
        vector<int> vs (256, 0);
        for(int i = 0; i < T.size(); ++i) vt[T[i]]++;
        
        int count = 0;
        int slow  = 0;
        int min_len = INT_MAX;
        int min_srt = 0;
        for(int fast = 0; fast < S.size(); ++fast){
            if(vt[S[fast]]){ // create window
                vs[S[fast]]++;
                if(vs[S[fast]] <= vt[S[fast]]) count++;
            }
            
            if(count == T.size()){ 
                while(!vt[S[slow]] || vs[S[slow]] > vt[S[slow]]){  // maintain window
                    if(vt[S[slow]]) vs[S[slow]]--;
                    slow++;
                }
                if(fast - slow + 1 < min_len){
                    min_len = fast - slow + 1;
                    min_srt = slow;
                }
            }
        }
        
        return min_len == INT_MAX ? "" : S.substr(min_srt, min_len);
    }
};