// #include <cmath>
class Solution {
private:
    int sum = 0;
public:
    // dfs (classic)
    int totalNQueens(int n) {
        int A[n];
        fill_n(A, n, 0);
        
        // put an element in a row each time, thus elimilate row duplicates
        dfs(A, 0, n);
        return sum;
    }
    // fill the puzzle row by row
    void dfs(int A[], int row, int n){ 
        if(row == n){
            sum++;
            return;
        }
        for(int j = 0; j < n; j++){
            if(isValid(A, row, j)){
                A[row] = j;
                dfs(A, row+1, n);
            }
        }
    }
    bool isValid(int A[], int row, int col){
        for(int i = 0; i < row; i++){
            if(A[i] == col || abs(A[i] - col) == abs(i - row))
                return false;
        }
        return true;
    }
};