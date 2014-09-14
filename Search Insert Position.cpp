class Solution {
public:
    // binary search
    int searchInsert(int A[], int n, int target) {
        int l = 0;
        int h = n - 1;
        while(l <= h){
            int m = (l + h) / 2;
            if(target == A[m]) return m;
            if(l < m && A[m-1] < target && target < A[m]) return m; // key
            if(target < A[m])
                h = m - 1;
            else
                l = m + 1;
        }
        return l;
    }
};