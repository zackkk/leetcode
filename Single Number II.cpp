class Solution {
public:
    // bit manipulation
    int singleNumber(int A[], int n) {
        int ret = 0;
        // consider each bit
        for(int i = 0; i < 32; i++){
            int bitsum = 0;
            for(int j = 0; j < n; j++){
                bitsum += ((A[j] >> i) & 1);
            }
            ret |= ((bitsum % 3) << i);
        }
        return ret;
    }
};