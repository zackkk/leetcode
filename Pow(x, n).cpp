class Solution {
public:
    // brute-force: 2^10 = 2*2*2*2*2*2*2*2*2*2
    // 2^10 =  4^5
    // 4^5  =  16^2 * 4
    // 16^2 =  256^1
    // 256^1 return
    double pow(double x, int n) {
        if(n == 0) return 1;
        if(n == 1) return x;
        if(n < 0) {x = 1/x; n = -n;}  // corner case
        if(n % 2 == 0) 
            return pow(x*x, n/2); // more space, less time: log(N)
        else 
            return x*pow(x*x, n/2);
        
    }
};