class Solution {
public:
    // set, erase
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> m;
        for(int i : num)
            m.insert(i);
        int max_len = 0;
        for(auto it = m.begin(); it != m.end(); ++it){
            int count = 1;
            int left = *it - 1;
            int right = *it + 1;
            
            while(m.find(left) != m.end()){
                count++;
                m.erase(left);
                left--;
            }
            
            while(m.find(right) != m.end()){
                count++;
                m.erase(right);
                right++;
            }
            max_len = max(max_len, count);
        }
        return max_len;
    }
};