class Solution {
public:
    // always step to the farthest distance
    int jump(int A[], int n) {
        if(n <= 1) return 0;
        int steps = 1;
        int maxDistCanReach = A[0];
        int next_maxDistCanReach = maxDistCanReach;
        for(int i = 1; i < n; i++){
            if(i > maxDistCanReach){
                maxDistCanReach = next_maxDistCanReach;
                steps++;
            }
            if(A[i] + i > next_maxDistCanReach){
                next_maxDistCanReach = A[i] + i;
            }
        }
        return steps;
    }
};