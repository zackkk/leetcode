class Solution {
public:
    bool canJump(int A[], int n) {
        int curMaxDist = 0;
    
        for(int i = 0; i < n; i++){
            if(i + A[i] > curMaxDist)
                curMaxDist = i + A[i];
            if(curMaxDist <= i) // can't go to the next position
                break;
        }
        if(curMaxDist >= n-1)
            return true;
        else
            return false;
    }
};