class Solution {
public:
    // dfs, point: return true/false, rather than collect value set
    void solveSudoku(vector<vector<char> > &board) {
        dfs(board, 0, 0);
    }
    
    bool dfs(vector<vector<char>> &board, int row, int col){
        if(col == 9) return dfs(board, row+1, 0);
        if(row == 9) return true;
        
        if(board[row][col] != '.'){
            return dfs(board, row, col+1);
        }
        else{
            for(char val = '1'; val <= '9'; ++val){
                if(isValid(board, row, col, val)){
                    board[row][col] = val;
                    if(dfs(board, row, col+1))
                        return true;
                    board[row][col] = '.';
                }
            }   
            return false;
        }
    }
    
    bool isValid(vector<vector<char>> &board, int row, int col, char v){
        for(int j = 0; j < 9; ++j){
            if(board[row][j] == v) return false;
        }
        
        for(int i = 0; i < 9; ++i){
            if(board[i][col] == v) return false;
        }
        
        for(int i = row/3*3; i < row/3*3+3; ++i){
            for(int j = col/3*3; j < col/3*3+3; ++j){
                if(board[i][j] == v) return false;
            }   
        }
        return true;
    }
};