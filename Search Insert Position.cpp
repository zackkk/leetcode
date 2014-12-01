class Solution {
public:
    // binary search
    int searchInsert(int A[], int n, int target) {
        
        int lo = 0;
        int hi = n-1;
    
        while(lo <= hi){
            int mi = lo + (hi - lo) / 2;
            if(A[mi] == target) return mi;
            if(A[mi] > target && mi == 0) return 0;
            if(A[mi] < target && mi == n-1) return n;
            if(A[mi-1] < target && A[mi] > target) return mi;
            
            if(A[mi] > target)
                hi = mi - 1;
            else
                lo = mi + 1;
        }
    }
};