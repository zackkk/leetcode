class Solution {
public:
    // always step to the farthest distance
    int jump(int A[], int n) {
        if(n <= 1) return 0;
        int steps = 1;
        int canJumpMaxDist = A[0];
        int next_canJumpMaxDist = A[0];
        for(int i = 1; i < n; i++){
            if(i > canJumpMaxDist){
                canJumpMaxDist = next_canJumpMaxDist;
                steps++;
            }
            next_canJumpMaxDist = max(next_canJumpMaxDist, A[i] + i);
        }
        return steps;
    }
};