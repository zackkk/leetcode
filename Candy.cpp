class Solution {
public:
    // 3 line types: increasing, decreasing, horizontal.
    int candy(vector<int> &ratings) {
        vector<int> candies (ratings.size(), 1);
        
        // increasing line
        for(int i = 0; i < ratings.size() - 1; i++){
            if(ratings[i] < ratings[i+1])
                candies[i+1] = candies[i] + 1;
        }
        
        // decreasing line
        for(int j = ratings.size() - 1; j > 0; j--){
            if(ratings[j-1] > ratings[j]){
                if(candies[j-1] <= candies[j]) // its previous point may be increased before
                    candies[j-1] = candies[j] + 1;
            }
        }
        
        int ret = 0;
        for(int i = 0; i < candies.size(); i++)
            ret += candies[i];
        return ret;
    }
};