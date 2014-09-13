class Solution {
public:
    double pow(double x, int n) {
       
        if(n == 0) return 1;
        if(n == 1) return x;
        if(n < 0) {x = 1/x; n = -n;}
        if(n % 2 == 0) 
            return pow(x*x, n/2); // more space, less time log(N)
        else 
            return x*pow(x*x, n/2);
        
    }
};