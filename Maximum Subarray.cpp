class Solution {
public:
    int maxSubArray(int A[], int n) {
        int max_sum = INT_MIN;
        int tmp_sum = 0;
        for(int i = 0; i < n; ++i){
            tmp_sum = max(tmp_sum + A[i], A[i]);
            max_sum = max(tmp_sum, max_sum);
        }
        return max_sum;
    }
};