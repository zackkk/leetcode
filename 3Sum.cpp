class Solution {
public:
    // n-sum, sort, avoid duplicates
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int>> ret;
        if(num.size() < 3) return ret;
        
        for(int i = 0; i < num.size() - 2; i++){
            if (i > 0 && num[i] == num[i-1]) continue; // avoid duplicates, bug happened here
            int left = i + 1;
            int right = num.size() - 1;
            while(left < right){
                int sum = num[i] + num[left] + num[right];
                if(sum == 0){
                    vector<int> vec (3, 0); // bug happened here
                    vec[0] = num[i];
                    vec[1] = num[left];
                    vec[2] = num[right];
                    ret.push_back(vec);
                    left++;
                    right--;
                    while(left < right && num[left] == num[left-1]) left++; // avoid duplicates
                    while(left < right && num[right] == num[right+1]) right--;
                }
                else if(sum < 0){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return ret;
    }
};