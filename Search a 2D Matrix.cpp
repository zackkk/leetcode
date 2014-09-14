class Solution {
public:
    // binary search: transfer 2d into 1d
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int start = 0;
        int end = m * n - 1;
        while(start <= end){
            int mid = (start + end) / 2;
            int num = matrix[mid / n][mid % n];
            if(target == num)
                return true;
            if(target > num)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return false;
    }
};