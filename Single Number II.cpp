class Solution {
public:
    // bit manipulation
    int singleNumber(int A[], int n) {
        int ret = 0;
        // consider each bit
        for(int i = 0; i < 32; i++){
            int tmp = 0;
            for(int j = 0; j < n; j++){
                tmp += ((A[j] >> i) & 1);
            }
            ret |= ((tmp % 3) << i);
        }
        return ret;
    }
};