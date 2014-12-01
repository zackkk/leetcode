class Solution {
public:
    // math ---> construct a tree & maintain a remaining chars string
    string getPermutation(int n, int k) {
        
        string nums = "";
        vector<int> fact (n+1, 0); // factorial
        for(int i = 1; i <= n; ++i){
            nums  += to_string(i);
            fact[i] = i == 1 ? 1 : fact[i-1] * (i);
        }
        
        k--;
        string ret = "";
        while(n > 2){
            int i = k / fact[n-1];
            ret += nums[i];
            nums.erase(i,1);
            
            k = k % fact[n-1];
            n--;
        }        
        if(k == 1) reverse(nums.begin(), nums.end()); // two elements
        ret += nums;
        
        return ret;
    }
};