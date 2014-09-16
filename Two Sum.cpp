class Solution {
public:
    // solution 1: sort, left & right pointers: O(NlogN + N) ---> sort value will mess up index
    // solution 2: map: O(NlogN) 
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ret;
        map<int,int> m; // <value, index>
        for(int i = 0; i < numbers.size(); i++){
            if(m[target - numbers[i]]){
                ret.push_back(m[target - numbers[i]]);
                ret.push_back(i+1); // not zero-based.
                break;
            }
            else{
                m[numbers[i]] = i+1; // not zero-based.
            }
        }
        return ret;
    }
};