class Solution {
public:
    // brute-force: O(N) ---> binary search: O(logN)
    int sqrt(int x) {
        if(x <= 1) return x;
        long long lo = 1;
        long long hi = x/2;
        while(lo <= hi){
            long long mi = lo + (hi - lo) / 2;
            if(mi * mi == x) return (int)mi;
            if(mi * mi < x)
                lo = mi + 1;
            else
                hi = mi - 1;
        }
        if(lo * lo > x) return (int)(lo - 1); // corner case
    }
};