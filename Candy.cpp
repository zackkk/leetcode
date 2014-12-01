class Solution {
public:
    // abstract the question as a "line" model: 3 line types: increasing, decreasing and horizontal.
    int candy(vector<int> &ratings) {
        int n = ratings.size();
        if(n == 0) return 0;
        vector<int> v (n, 1);
        for(int i = 1; i < n; ++i){
            if(ratings[i] > ratings[i-1])
                v[i] = v[i-1] + 1;
        }
        for(int i = n - 2; i >= 0; --i){
            if(ratings[i] > ratings[i+1] && v[i] <= v[i+1]) // "="
                v[i] = v[i+1] + 1;
        }
        
        int sum = 0;
        for(int i : v) sum += i;
        return sum;
    }
};