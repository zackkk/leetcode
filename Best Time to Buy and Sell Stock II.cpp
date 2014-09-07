class Solution {
public:
    int maxProfit(vector<int> &prices) {
        unsigned ret = 0;
        for(unsigned i = 1; i < prices.size(); i++){
            if(prices[i] > prices[i-1]){
                // buy a stock if its price increased
                ret += (prices[i] - prices[i-1]);  
            }
        }
        return ret;
    }
};