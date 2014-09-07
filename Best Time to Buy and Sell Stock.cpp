class Solution {
public:
    // at most one transaction, buy(lowest) then sell(highest)
    int maxProfit(vector<int> &prices) {
        if(prices.empty())
            return 0;
        int ret = 0;
        int lowPrice = prices[0];
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] - lowPrice > ret)
                ret = prices[i] - lowPrice;
            lowPrice = prices[i] < lowPrice ? prices[i] : lowPrice;
        }
        return ret;
    }
};