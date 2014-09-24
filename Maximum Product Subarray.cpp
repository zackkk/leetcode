class Solution {
public:
    // record max, min
    int maxProduct(int A[], int n) {
        int ret = INT_MIN;
        int imax = 1; // max是到当前为止最大的正product
        int imin = 1; // min是到当前为止最小的负product，或者1。
        for(int i = 0; i < n; i++){
            if(A[i] == 0){
                ret = max(ret, 0); // corner case
                
                imax = 1;
                imin = 1;
            }
            else if(A[i] > 0){
                ret = max(ret, imax * A[i]);
                
                imax = imax * A[i];
                imin = min(imin * A[i], 1);
            }
            else if(A[i] < 0){
                ret = max(ret, imin * A[i]);
                
                int tmp = imax;
                imax = max(imin * A[i], 1);
                imin = tmp * A[i];
            }
            else
                ;
        }
        return ret;
    }
};