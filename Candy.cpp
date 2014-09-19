class Solution {
public:
    // abstract the question as a "line" model: 3 line types: increasing, decreasing, horizontal.
    int candy(vector<int> &ratings) {
        int sz = ratings.size();
        vector<int> candies (sz, 1);
        
        // increasing line
        for(int i = 0; i < sz - 1; i++){
            if(ratings[i] < ratings[i+1])
                candies[i+1] = candies[i] + 1;
        }
        
        // decreasing line
        for(int j = sz - 1; j > 0; j--){
            if(ratings[j-1] > ratings[j]){
                if(candies[j-1] <= candies[j]) // its previous point may be increased before
                    candies[j-1] = candies[j] + 1;
            }
        }
        
        int ret = 0;
        for(int i : candies)
            ret += i;
        return ret;
    }
};