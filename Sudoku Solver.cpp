class Solution {
public:
    // dfs, point: return true/false, rather than collect value set
    void solveSudoku(vector<vector<char> > &board) {
        // start fill blanks from point(0,0)
        dfs(board, 0, 0); 
    }
    bool dfs(vector<vector<char>> &board, int row, int col){
        if(col == 9) return dfs(board, row+1, 0); // next row
        if(row == 9) return true;
        if(board[row][col] == '.'){ 
            for(char val = '1'; val <= '9'; val++){
                if(isValid(board, row, col, val)){
                    board[row][col] = val;
                    if(dfs(board, row, col+1)) return true;
                    board[row][col] = '.';
                }
            }
            return false;
        }
        else{
            return dfs(board, row, col+1);
        }
    }
    
    bool isValid(vector<vector<char> > &board, int row, int col, char val){
        // check same row
        for(int j = 0; j < 9; j++){
            if(board[row][j] == val)
                return false;
        }
        
        // check same col
        for(int i = 0; i < 9; i++){
            if(board[i][col] == val)
                return false;
        }
        
        // check sub-grid
        for(int i = row/3*3; i < row/3*3 + 3; i++){
            for(int j = col/3*3; j < col/3*3 +3; j++){
                if(board[i][j] == val)
                    return false;
            }
        }
        
        return true;
    }
};