class Solution {
public:
    // solution1 : 64 = 8 + 8 + 8 + 8 + 8 + 8 + 8 + 8
    // solution2 : 64 = 8 + (8+8) + ((8+8)+(8+8)) +  (((8+8)+(8+8))+((8+8)+(8+8)) over! )
    //                = 8 + (8+8) + ...
    // solution3:  64 = 8(2^3) + 16(2^4) + ...
    int divide(int dividend, int divisor) {
        long long y = dividend; // avoid overflow
        long long x = divisor;
        y = abs(y);
        x = abs(x);

        int count = 0;
        while(y >= x){
            long long tmpSum = x;
            int tmpCount = 1;
            for(; y >= tmpSum; tmpSum<<=1, tmpCount<<=1){ // (a<<=1) == (a += a)
                y -= tmpSum;
                count += tmpCount;
            }
        }
        return ((dividend > 0) ^ (divisor > 0)) ? -count : count; // check sign
    }
};