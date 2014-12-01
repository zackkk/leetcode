class Solution {
public:
    // bit manipulation
    int singleNumber(int A[], int n) {
        int ret = 0;
        for(int i = 0; i < 32; ++i){
            int sum = 0;
            for(int j = 0; j < n; ++j){
                sum += A[j] >> i & 1; 
            }
            sum %= 3;
            ret += sum << i;
        }
        return ret;
    }
};