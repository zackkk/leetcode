class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ret (2, -1);
        map<int, int> m; // num, index
        for(int i = 0; i < numbers.size(); ++i){
            int num = numbers[i];
            if(m[target - num]){
                ret[0] = m[target - num]; 
                ret[1] = i + 1;
                return ret;
            }
            else{
                m[num] = i + 1; // "1" based
            }
        }
        return ret;
    }
};