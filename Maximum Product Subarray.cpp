class Solution {
public:
    // record max, min
    int maxProduct(int A[], int n) {
        int ret = A[0];
        int imax = A[0];
        int imin = A[0];
        for(int i = 1; i < n; ++i){
            if(A[i] < 0) swap(imax, imin);
            
            imax = max(A[i], A[i] * imax);
            imin = min(A[i], A[i] * imin);
            
            ret = max(ret, imax);
        }
        return ret;
    }
};