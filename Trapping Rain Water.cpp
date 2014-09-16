class Solution {
public:
    // water volumn depends on left max height and right max height
    int trap(int A[], int n) {
        if(A == NULL || n == 0) return 0;
        int maxWater = 0;
        int leftMaxHeight = A[0];
        for(int i = 1; i < n - 1; i++){ // skip the first&last one
            int rightMaxHeight = 0;
            for(int j = i+1; j < n; j++) rightMaxHeight = max(rightMaxHeight, A[j]);
            if(min(leftMaxHeight, rightMaxHeight) > A[i])
                maxWater += (min(leftMaxHeight, rightMaxHeight) - A[i]);
            leftMaxHeight = max(leftMaxHeight, A[i]);
        }
        return maxWater;
    }
};