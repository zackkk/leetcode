class Solution {
public:
    // set, erase
    int longestConsecutive(vector<int> &num) {
        int maxlen = 0;
        unordered_set<int> myset; // point: unsorted_set for O(1) look up
        for(int i = 0; i < num.size(); i++)
            myset.insert(num[i]);
        for(auto it = myset.begin(); it != myset.end(); ++it){ // point: auto
            int count = 1;
            int left = *it - 1;
            int right = *it + 1;
            // myset.erase(*it); can't earse iterator?
            while(myset.find(left) != myset.end()){ // find in O(1)
                count++;
                myset.erase(left);
                left--;
            }
            while(myset.find(right) != myset.end()){
                count++;
                myset.erase(right);
                right++;
            }
            maxlen = max(maxlen, count);
        }
        return maxlen;
    }
};