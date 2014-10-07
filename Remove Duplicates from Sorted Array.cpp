class Solution {
public:
    // slow & fast "pointers"
    int removeDuplicates(int A[], int n) {
        if(n <= 1) return n;
        int slow = 0;
        for(int fast = 0; fast < n; fast++){
            if(A[slow] != A[fast]){
                slow++;
                A[slow] = A[fast];
            }
        }
        return slow+1;
    }
};