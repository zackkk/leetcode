class Solution {
public:
    // binary search, CC150
    int search(int A[], int n, int target) {
        int lo = 0;
        int hi = n-1;
        while(true){
            if(lo > hi) return -1;
            int mi = lo + (hi - lo) / 2;
            if(A[mi] == target) return mi;
            
            if(A[lo] <= A[mi]){ // bug here without "="
                if(A[lo] <= target && target <= A[mi])
                    hi = mi - 1;
                else
                    lo = mi + 1;
            }
            else{
                if(A[mi] <= target && target <= A[hi])
                    lo = mi + 1;
                else
                    hi = mi - 1;
            }
        }
    }
};