class Solution {
public:
    // 1. combine two arrays
    // 2. find k th, O(log(m+n))
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if((m+n)%2 != 0)
            return findK(A, m, B, n, (m+n)/2+1, 0, 0);
        else
            return (findK(A, m, B, n, (m+n)/2, 0, 0) + findK(A, m, B, n, (m+n)/2+1, 0, 0) ) / 2.0;
    }
    
    double findK(int A[], int m, int B[], int n, int k, int a, int b){
        
        if(a >= m) return B[b+k-1];
        if(b >= n) return A[a+k-1];
        if(k == 1) return min(A[a], B[b]);
        
        int key_A = a+k/2-1 < m ? A[a+k/2-1] : INT_MAX;
        int key_B = b+k/2-1 < n ? B[b+k/2-1] : INT_MAX;
        
        if(key_A < key_B)
            return findK(A, m, B, n, k-k/2, a+k/2, b); // didn't use return...
        else
            return findK(A, m, B, n, k-k/2, a, b+k/2);
    }
};