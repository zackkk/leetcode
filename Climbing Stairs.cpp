class Solution {
public:
    // 1d dp
    int climbStairs(int n) {
        int steps[n+1]; 
        fill_n(steps, n+1, 0);
        if(n <= 2)
            return n;
        steps[1] = 1;
        steps[2] = 2;
        
        for(int i = 3; i <= n; i++){
            steps[i] = steps[i-1] + steps[i-2];
        }
        return steps[n];
    }
};