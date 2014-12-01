class Solution {
public:
    // three "pointers" trick, size of array is already known as n.
    void sortColors(int A[], int n) {
        if(A == NULL || n <= 1) return;
        
        int zero = 0;
        int two = n - 1;
        int i = 0;
        while(i <= two){
            if(A[i] == 0){
                swap(A, zero, i);
                zero++;
                i++;
            }
            else if(A[i] == 2){
                swap(A, two, i);
                two--;
            }
            else{
                i++;
            }
        }
    }
    
    void swap(int *A, int i, int j){ // "int *A"
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
    }
};