class Solution {
public:
    // binary search
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ret (2, -1);
        int pos = binarySearch(A, 0, n-1, target);
        if(pos == -1) return ret;
        
        int left = pos;
        int right = pos;
        while(left - 1 >= 0 && A[left - 1] == target) left--;
        while(right + 1 < n && A[right + 1] == target) right++;
        ret[0] = left;
        ret[1] = right;
        return ret;
    }
    
    int binarySearch(int A[], int low, int high, int target){
        if(low > high) return -1;
        int mid = (low + high) / 2;
        if(A[mid] == target) return mid;
        if(low <= mid-1 && A[low] <= target && target <= A[mid-1])
            return binarySearch(A, low, mid-1, target);
        else if(mid+1 <= high && A[mid+1] <= target && target <= A[high])
            return binarySearch(A, mid+1, high, target);
        else
            return -1;
    }
};