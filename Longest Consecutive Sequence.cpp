class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int maxLen = 0;
        unordered_set<int> mySet; // point: unsorted_set for O(1) look up
        for(int i = 0; i < num.size(); i++)
            mySet.insert(num[i]);
        for(auto it = mySet.begin(); it != mySet.end(); it++){ // point: auto
            int count = 1;
            int left = *it - 1;
            int right = *it + 1;
            while(mySet.find(left) != mySet.end()){ // find in O(1)
                count++;
                mySet.erase(left);
                left--;
            }
            while(mySet.find(right) != mySet.end()){
                count++;
                mySet.erase(right);
                right++;
            }
            maxLen = count > maxLen ? count : maxLen;
        }
        return maxLen;
    }
};