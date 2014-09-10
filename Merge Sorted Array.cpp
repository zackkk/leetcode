class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = m + n -1;
        // treat m & n as indexes
        m--;
        n--;
        while(n >= 0){
            if(m < 0 || B[n] > A[m]){
                A[i] = B[n];
                n--;
            }
            else{
                A[i] = A[m];
                m--;
            }
            i--;
        }
    }
};