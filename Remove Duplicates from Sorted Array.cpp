class Solution {
public:
    // slow & fast
    int removeDuplicates(int A[], int n) {
        if(n <= 1) return n;
        int slow = 0;
        for(int fast = 1; fast < n; fast++){
            if(A[fast] != A[slow]){
                slow++;
                A[slow] = A[fast];
            }
        }
        return slow+1;
    }
};