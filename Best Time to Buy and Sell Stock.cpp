class Solution {
public:
    // at most one transaction, buy(lowest) then sell(highest)
    int maxProfit(vector<int> &prices) {
        if(prices.empty()){
            return 0;
        }
        
        int maxprofit = 0;
        int low = prices[0];
        for(int i = 1; i < prices.size(); i++){
            maxprofit = max(maxprofit, prices[i] - low);
            low = min(low, prices[i]);
        }
        return maxprofit;
    }
};