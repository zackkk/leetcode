class Solution {
public:
    // straight-forward implementation, fixed series
    string countAndSay(int n) {
        string prev = "1";
        for(int i = 2; i <= n; i++){
            string cur = "";
            int j = 0;
            while(j < prev.size()){
                char tmp_char = prev[j];
                int tmp_count = 1;
                while(j+1 < prev.size() && prev[j+1] == tmp_char){
                    tmp_count++;
                    j++;
                }
                cur += to_string(tmp_count);
                cur += tmp_char;
                j++;
            }
            prev = cur;
        }
        return prev;
    }
};