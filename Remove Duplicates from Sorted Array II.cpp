class Solution {
public:
    // extra space : map
    // in place : count the number of "slow"
    int removeDuplicates(int A[], int n) {
        if(n <= 1) return n;
        int slow = 0;
        int count = 1;
        for(int fast = 1; fast < n; fast++){
            // new element
            if(A[fast] != A[slow]){
                count = 1;
                slow++;
                A[slow] = A[fast];
            }
            // duplicates
            else{ // A[fast] == A[slow]
                count++;
                if(count <= 2){
                    slow++;
                    A[slow] = A[fast];
                }
            }
        }
        return slow+1;
    }
};