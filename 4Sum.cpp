class Solution {
public:
    // n-sum, left & right pointers
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int>> ret;
        int sz = num.size();
        if(sz < 4) return ret;
        for(int i = 0; i <= sz-4; i++){
            for(int j = i+1; j <= sz-3; j++){
                int left = j+1;
                int right = sz-1;
                while(left < right){
                    int sum = num[i]+num[j]+num[left]+num[right];
                    if(sum == target){
                        vector<int> vec;
                        vec.push_back(num[i]);
                        vec.push_back(num[j]);
                        vec.push_back(num[left]);
                        vec.push_back(num[right]);
                        ret.push_back(vec);
                        left++;
                        right--;
                    }
                    else if(sum < target)
                        left++;
                    else
                        right--;
                }
            }
        }
        // clear duplicates
        set<vector<int>> mySet;
        for(int i = 0; i < ret.size(); i++) mySet.insert(ret[i]);
        ret.clear();
        ret.assign(mySet.begin(), mySet.end());
        return ret;
    }
};