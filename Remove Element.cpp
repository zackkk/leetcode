class Solution {
public:
    // slow & fast "pointers"
    int removeElement(int A[], int n, int elem) {
        int slow = 0;
        for(int fast = 0; fast < n; fast++){
            if(A[fast] != elem){
                A[slow] = A[fast];
                slow++;
            }
        }
        return slow;
    }
};