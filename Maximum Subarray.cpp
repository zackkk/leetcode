class Solution {
public:
    int maxSubArray(int A[], int n) {
        int max = INT_MIN;
        int subMax = 0;
        for(int i = 0; i < n; i++){
            subMax = subMax+A[i] > A[i] ? subMax+A[i] : A[i];
            max = subMax > max ? subMax : max;
        }
        return max;
    }
};