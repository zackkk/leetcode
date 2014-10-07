class Solution {
public:
    // jump as far as you can
    bool canJump(int A[], int n) {
        int canJumpMaxDist = 0;
    
        for(int i = 0; i < n; i++){
            canJumpMaxDist = max(canJumpMaxDist, i + A[i]);
            if(canJumpMaxDist == i) // can't go to the next position
                break;
        }
        return canJumpMaxDist >= n-1 ? true : false;
    }
};