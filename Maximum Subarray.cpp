class Solution {
public:
    int maxSubArray(int A[], int n) {
        int maxsum = INT_MIN;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum = max(sum + A[i] , A[i]);
            maxsum = max(maxsum, sum);
        }
        return maxsum;
    }
};