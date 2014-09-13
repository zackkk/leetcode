class Solution {
public:
    // same as Palindrome Number
    int reverse(int x) {
        int ret = 0;
        int sign = x > 0 ? 1 : -1;
        x *= sign; // absolute value
        while(x != 0){
            int rem = x % 10;
            ret = ret * 10 + rem;
            x = x / 10;
        }
        return sign * ret;
    }
};