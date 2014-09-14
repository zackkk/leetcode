class Solution {
public:
    void sortColors(int A[], int n) {
        int zero = 0;
        int one = 0;
        // no need to count two
        for(int i = 0; i < n; i++){
            if(A[i] == 0)
                zero++;
            else if(A[i] == 1)
                one++;
        }
        for(int i = 0; i < n; i++){
            if(zero > 0){
                A[i] = 0;
                zero--;
            }
            else if(one > 0){
                A[i] = 1;
                one--;
            }
            else{
                A[i] = 2;   
            }
        }
    }
};