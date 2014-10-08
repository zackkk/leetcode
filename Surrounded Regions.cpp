class Solution {
public:
    // dfs 'O' elements on the borders, use letter 'M' to avoid extra memory
    void solve(vector<vector<char>> &board) {
        if(board.size() == 0) return; // bug happened here !!!
        int rowNum = board.size();
        int colNum = board[0].size();
        
        // explore border elements
        for(int i = 0; i < rowNum; i++){
            if(board[i][0] == 'O') dfs(board, i, 0);
            if(board[i][colNum-1] == 'O') dfs(board, i, colNum-1);
        }
        for(int j = 0; j < colNum; j++){
            if(board[0][j] == 'O') dfs(board, 0, j);
            if(board[rowNum-1][j] == 'O') dfs(board, rowNum-1, j);
        }
        
        for(int i = 0; i < rowNum; i++){
            for(int j = 0; j < colNum; j++){
                board[i][j] = board[i][j] == 'M' ? 'O' : 'X';
            }
        }
    }
    
    void dfs(vector<vector<char>> &board, int row, int col){
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
            return;
        if(board[row][col] != 'O')
            return;
        board[row][col] = 'M'; // mark, then no need for an extra "visited" 2d vector
        dfs(board, row-1, col);
        dfs(board, row+1, col);
        dfs(board, row, col-1);
        dfs(board, row, col+1);
    }
};