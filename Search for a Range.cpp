class Solution {
public:
    // binary search
    vector<int> searchRange(int A[], int n, int target) {
        int index = binarySearch(A, n, target, 0, n-1);
        vector<int> ret (2, -1);
        if(index == -1) return ret;
        
        int left = index;
        int right = index;
        while(left - 1 >= 0 && A[left-1] == A[index]) left--;
        while(right + 1 < n && A[right+1] == A[index]) right++;
        ret[0] = left;
        ret[1] = right;
        return ret; 
    }
    
    int binarySearch(int A[], int n, int target, int lo, int hi){
        if(lo > hi) return -1;
        int mi = lo + (hi - lo) / 2;
        
        if(A[mi] == target) 
            return mi;
        else if(A[mi] < target)
            return binarySearch(A, n, target, mi+1, hi);
        else
            return binarySearch(A, n, target, lo, mi-1);
    }
};