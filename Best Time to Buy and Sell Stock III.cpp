class Solution {
public:
    // rule: buy in low price and then sell in high price ---> left & right idea
    // left[i]: max profit from first day to day i (global) for one transaction
    // right[i]: max profit from day i to last day (global) for one transaction
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if(n == 0) return 0;
        
        vector<int> left (n, 0);
        int left_max = 0;
        int left_low = prices[0];
        for(int i = 1; i < n; ++i){
            left[i] = max(left_max, prices[i] - left_low);
            left_max = max(left_max, left[i]);
            left_low = min(left_low, prices[i]);
        }
        
        vector<int> right (n, 0);
        int right_max = 0;
        int right_high = prices[n-1];
        for(int i = n - 2; i >= 0; --i){
            right[i] = max(right_max, right_high - prices[i]);
            right_max = max(right_max, right[i]);
            right_high = max(right_high, prices[i]);
        }
        
        int ret = 0;
        for(int i = 0; i < n; ++i)
            ret = max(ret, left[i] + right[i]);
        return ret;
    }
};