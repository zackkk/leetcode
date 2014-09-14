class Solution {
public:
    // brute-force: O(N) ---> binary search: O(logN)
    int sqrt(int x) {
        if(x <= 1) return x;
        long long low = 1;
        long long high = x / 2;
        while(low <= high){
            long long mid = (low + high) / 2;
            if(mid * mid == x) 
                return (int)mid;
            else if(mid * mid > x){ 
                high = mid - 1;
            }
            else 
                low = mid + 1;
        }
        // x is not a square number
        if(low * low > x) return (int)(--low);
    }
};