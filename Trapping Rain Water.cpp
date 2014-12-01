class Solution {
public:
    // water volumn depends on left max height and right max height
    int trap(int A[], int n) {
        if(n == 0) return 0;
    
        vector<int> left(n, 0); // highest bar on its left; 
        vector<int> right(n, 0);
        
        int left_max = 0;
        for(int i = 0; i < n; ++i){
            left[i] = left_max;
            left_max = max(A[i], left_max);
        }
        
        int right_max = 0;
        for(int i = n-1; i >= 0; --i){
            right[i] = right_max;
            right_max = max(A[i], right_max);
        }
        
        int water = 0;
        for(int i = 1; i < n-1; ++i){
            int tmp = min(left[i], right[i]) - A[i];
            if(tmp > 0) water += tmp;
        }
        return water;
    }
};