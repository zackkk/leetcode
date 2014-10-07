class Solution {
public:
    // two pointers, dynamicly maintain window frame that contains all chars in T
    string minWindow(string S, string T) {
        // <value, frequency>
        map<char, int> expect;
        map<char, int> current;
        for(int i = 0; i < T.size(); i++) expect[T[i]]++;
        int TCount = 0; // number of chars of T in the window
        int minStart = 0;
        int minLen = INT_MAX;
        int slow = 0;
        for(int fast = 0; fast < S.size(); fast++){
            
            // useful at the beginning, check if we have contained "T"
            if(expect[S[fast]]) { 
                current[S[fast]]++; 
                if(current[S[fast]] <= expect[S[fast]]) TCount++; 
            }
            
            // at least contain "T"
            if(TCount == T.size()){ 
                // move "slow", and ganrantee "current" will always contain T
                while(!expect[S[slow]] || current[S[slow]] > expect[S[slow]]){ 
                    if(expect[S[slow]]) current[S[slow]]--;
                    slow++;
                }
                if(fast - slow + 1 < minLen){
                    minLen = fast - slow + 1;
                    minStart = slow;
                }
            }
        }
        return minLen == INT_MAX ? "" : S.substr(minStart, minLen);
    }
};