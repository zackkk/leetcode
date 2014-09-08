class Solution {
public:
    // point: do it without using extra space.
    // put A[i] onto its desired position. 
    // for example, if A[0] == 4, then 4 should be put onto A[3], then we swap A[0] and A[3], then A[3] == 4. 
    int firstMissingPositive(int A[], int n) {
        for(int i = 0; i < n; i++){
            while(A[i] != i+1){
                if(A[i] <= 0 || A[i] > n) break; // not within the range
                
                int targetIndex = A[i] - 1;
                if(A[targetIndex] == A[i]) break; // already occupied, duplicates
                // swap
                A[i] = A[targetIndex];
                A[targetIndex] = targetIndex+1;
            }
        }
        // find the first missing number
        for(int i = 0; i < n; i++){
            if(A[i] != i+1)
                return i+1;
        }
        return n+1;
    }
};