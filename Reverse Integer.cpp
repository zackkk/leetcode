class Solution {
public:
    int reverse(int x) {
      
        int sign = x > 0 ? 1 : -1;
        long long y = abs(x);
        long long ret = 0;
        
        while(y != 0){
            ret = ret * 10 + y % 10;
            if(ret > INT_MAX || ret < INT_MIN) return 0;// new test cases
            y /= 10;
        }

        return (int)sign*ret;
    }
};