class Solution {
public:
    // use itself as a hashmap. For example, if A[2] = 6, then we flip A[6-1] to negative, 
    // the first missing positive will be the first non-flipped number
    int firstMissingPositive(int A[], int n) {
        for(int i = 0; i < n; ++i)
            A[i] = A[i] <= 0 ? n+1 : A[i];
            
        for(int i = 0; i < n; ++i){
            int index = abs(A[i]) - 1;
            if(index < n && A[index] > 0) A[index] *= -1;
        }
        
        for(int i = 0; i < n; ++i){
            if(A[i] > 0) return i+1; 
        }
        return n+1;
    }
};