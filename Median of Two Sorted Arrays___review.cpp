class Solution {
public:
    // 1. combine two arrays
    // 2. find k th, O(log(m+n))
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int len = m + n;
        if(len % 2 != 0)
            return findKth(A, 0, B, 0, len/2+1, m, n);
        else
            return (findKth(A, 0, B, 0, len/2, m, n) + findKth(A, 0, B, 0, len/2+1, m, n)) / 2.0;
    }
    // find Kth element of two sorted array, time complexity: logK
    double findKth(int A[], int A_start, int B[], int B_start, int k, int m, int n){ // no need to maintain "end" variable
        if(A_start >= m) return B[B_start + k - 1];
        if(B_start >= n) return A[A_start + k - 1];
        if(k == 1) return min(A[A_start], B[B_start]);
    
        int A_key = A_start+k/2-1 < m ? A[A_start+k/2-1] : INT_MAX;  // corner case
        int B_key = B_start+k/2-1 < n ? B[B_start+k/2-1] : INT_MAX;
        
        // If A[k/2] < B[k/2]
        //    A's first k-half is less than A's second k-half & B's second k-half
        //    A's first k-half is part of first k elements
        // Now, the kth element can be in A[k/2 + 1] to A[k] or B[1] to B[k/2]. 
        if(A_key < B_key) 
            return findKth(A, A_start+k/2, B, B_start, k - k/2, m, n); // no need to get rid of the second part of B implicitly
        else
            return findKth(A, A_start, B, B_start+k/2, k - k/2, m, n);
    }
};