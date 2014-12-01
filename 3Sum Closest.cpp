class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int n = num.size(); 
        if(n < 3) return 0;
        
        sort(num.begin(), num.end());
        int sum = 0;
        int diff = INT_MAX;
        for(int i = 0; i < n - 2; ++i){
            int l = i+1;
            int r = n-1;
            while(l < r){
                int tmp = num[i] + num[l] + num[r];
                if(abs(tmp - target) < diff){
                    sum = tmp;
                    diff = abs(tmp - target);
                }
                if(tmp < target) 
                    l++;
                else
                    r--;
            }
        }
        return sum;
    }
};