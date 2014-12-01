class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n == 0) return 0;
        
        int prev_index = 0;
        int prev_val = A[0];
        int count = 1;
        
        for(int i = 1; i < n; ++i){
            if(A[i] == prev_val){
                if(count == 1){
                    prev_index++;
                    A[prev_index] = prev_val;
                    count++;
                }
            } 
            else{
                prev_index++;
                prev_val = A[i];
                A[prev_index] = prev_val;
                count = 1;
            }
        }
        return prev_index + 1;
    }
};