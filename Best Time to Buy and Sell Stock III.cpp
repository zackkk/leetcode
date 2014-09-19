class Solution {
public:
    // rule: buy in low price and then sell in high price ---> left & right idea
    // left[i]: max profit from first day to day i (global) for one transaction
    // right[i]: max profit from day i to last day (global) for one transaction
    int maxProfit(vector<int> &prices) {
        int len = prices.size();
        if(len <= 1) return 0;
        
        vector<int> left (len, 0);
        vector<int> right (len, 0);
        
        // dp from left to right
        left[0] = 0; // no trade no money
        int low = prices[0];
        for(int i = 1; i < len; i++){
            low = min(low, prices[i]);
            left[i] = max(left[i-1], prices[i] - low); // global max vs local max
        }
        
        // dp from right to left
        right[len-1] = 0;
        int high = prices[len-1];
        for(int i = len-2; i >= 0; i--){
            high = max(high, prices[i]);
            right[i] = max(right[i+1], high - prices[i]); // global max vs local max
        }
        
        int ret = 0;
        for(int i = 0; i < len; i++)
            ret = max(ret, left[i]+right[i]);
        return ret;
    }
};