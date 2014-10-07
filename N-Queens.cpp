class Solution {
public:
    // dfs (classic)
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<string> vec;
        vector<int> A (n, 0); // auto get rid of row duplicates, can't use array since n is unknown
        dfs(ret, A, n, 0);
        return ret;
    }
    
    void dfs(vector<vector<string>> &ret, vector<int> &A, int n, int row){
        // produce result
        if(row == n){
            vector<string> vec;
            for(int i = 0; i < n; i++){
                string str = "";
                for(int j = 0; j < n; j++){
                    char c;
                    c = j == A[i] ? 'Q' : '.';
                    str += c;
                }
                vec.push_back(str);
            }
            ret.push_back(vec);
        }
        
        for(int col = 0; col < n; col++){
            if(isValid(A, row, col)){
                A[row] = col;
                dfs(ret, A, n, row+1);
                // no need to pop(), replace directly
            }
        }
    }
    
    bool isValid(vector<int> &A, int row, int col){
        for(int i = 0; i < row; i++){ // check all previous rows
            if(A[i] == col) return false;
            if(abs(row - i) == abs(A[i] - col)) return false;
        }
        return true;
    }
};