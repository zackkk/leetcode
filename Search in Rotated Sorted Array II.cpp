class Solution {
public:
    // binary search, CC150
    bool search(int A[], int n, int target) {
        int lo = 0;
        int hi = n - 1;
        while(lo <= hi){
            int mi = lo + (hi - lo) / 2;
            if(A[mi] == target) return true;
            
            if(A[lo] < A[mi]){
                if(A[lo] <= target && target <= A[mi])
                    hi = mi - 1;
                else
                    lo = mi + 1;
            }
            else if(A[lo] == A[mi]) // point
                lo++;
            else{
                if(A[mi] <= target && target <= A[hi])
                    lo = mi + 1;
                else
                    hi = mi - 1;
            }
        }
        return false;
    }
};