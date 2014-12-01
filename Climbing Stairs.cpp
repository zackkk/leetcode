class Solution {
public:
    // 1d dp, we can get to stair case N either from N-2 (2 steps) or N-1 (1 step)
    int climbStairs(int n) {
        if(n <= 2) return n;
        int a = 1;
        int b = 2;
        for(int i = 3; i <= n; ++i){
            int tmp = b;
            b = a + b;
            a = tmp;
        }
        return b;
    }
};