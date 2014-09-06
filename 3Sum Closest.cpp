class Solution {
public:
    // left, right pointers trick
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        
        if(num.size() == 0)
            return 0;
        if(num.size() == 1)
            return num[0];
        if(num.size() == 2)
            return num[0] + num[1];
        
        int sum = 0;
        int minDiff = INT_MAX;
        for(int i = 0; i <= num.size() - 3; i++){
            int left = i+1;
            int right = num.size()-1;
            while(left < right){
                
                // check value pair
                int diff = abs(num[i] + num[left] + num[right] - target);
                if(diff < minDiff){
                    minDiff = diff;
                    sum = num[i] + num[left] + num[right];
                }
                
                // update pointers
                if(num[i] + num[left] + num[right] < target)
                    left++;
                else
                    right--;
            }
        }
        return sum;
    }
};