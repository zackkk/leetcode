class Solution {
public:
    string countAndSay(int n) {
        string prev = "1";
        for(int i = 2; i <= n; i++){
            string cur = "";
            int j = 0;
            while(j < prev.size()){
                char c = prev[j];
                int c_count = 1;
                while(j+1 < prev.size() && prev[j+1] == c){
                    c_count++;
                    j++;
                }
                cur += to_string(c_count);
                cur += c;
                j++;
            }
            
            prev = cur;
        }
        return prev;
    }
};