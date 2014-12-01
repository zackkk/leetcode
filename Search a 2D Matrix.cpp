class Solution {
public:
    // binary search: transfer 2d into 1d
    // if the second condition doesn't, then we can start from the right-top corner.
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size();
        if(m == 0) return false;
        int n = matrix[0].size();
        
        int lo = 0;
        int hi = m * n - 1;
        
        while(lo <= hi){
            int mi = lo + (hi - lo) / 2;
            int num = matrix[mi/n][mi%n];
            
            if(num == target) return true;
            if(num > target)
                hi = mi - 1;
            else
                lo = mi + 1;
        }
        return false;
    }
};