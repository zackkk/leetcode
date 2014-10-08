class Solution {
public:
    // binary search, CC150
    bool search(int A[], int n, int target) {
        if(A == NULL || n == 0) return false;
        int l = 0;
        int h = n-1;
        while(l <= h){
            int m = l + (h-l)/2; // avoid overflow
            if(A[m] == target) return true;
            if(A[l] < A[m]){ // left sorted
                if(A[l] <= target && target < A[m])
                    h = m-1;
                else
                    l = m+1;
            }
            else if(A[l] == A[m]){   // the diff line compared with "no duplicates"
                l++; 
            }
            else{ // right sorted
                if(A[m] < target && target <= A[h])
                    l = m+1;
                else
                    h = m-1;
            }
        }
        return false;
    }
};