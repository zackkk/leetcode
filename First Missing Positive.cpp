class Solution {
public:
    // use itself as a hashmap. For example, if A[2] = 6, then we flip A[6-1] to negative, 
    // the first missing positive will be the first non-flip number
    int firstMissingPositive(int A[], int n){ 
        // eliminate negative numbers
        for(int i = 0; i < n; i++){
            A[i] = A[i] <= 0 ? n+1 : A[i]; // negative numbers can't be candidates
        }
        
        for(int i = 0; i < n; i++){
            int targetIndex = abs(A[i]) - 1;
            if(0 <= targetIndex && targetIndex < n && A[targetIndex] > 0){
                A[targetIndex] *= -1; // flip
            }
        }
        
        for(int i = 0; i < n; i++){
            if(A[i] >= 0)
                return i+1;
        }
        return n+1;
    }
};