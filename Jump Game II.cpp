class Solution {
public:
    // always step to the farthest distance
    int jump(int A[], int n) {
        if(n == 0) return 0;
        int max_dist = 0;
        int next_max_dist = A[0];
        int step = 0;
        
        for(int i = 0; i < n; ++i){
            if(max_dist < i){
                step++;
                max_dist = next_max_dist;
            }
            next_max_dist = max(next_max_dist, i + A[i]);
        }
        return step;
    }
};