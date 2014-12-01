class Solution {
public:
    // jump as far as you can
    bool canJump(int A[], int n) {
        if(n == 0) return true;
        int max_dist = A[0];
        for(int i = 0; i < n; i++){
            if(max_dist < i) return false;
            max_dist = max(max_dist, i + A[i]);
        }
        return true;
    }
};