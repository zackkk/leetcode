class Solution {
public:
    // dfs
    bool exist(vector<vector<char> > &board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited (m, vector<bool> (n, false));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    if(dfs(board, word, i, j, 0, visited))
                        return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>> &board, string word, int row, int col, int count, vector<vector<bool>> &visited){
        if(count == word.size())
            return true;
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) // out of boundary, bug happened here.
            return false;
        if(visited[row][col] || board[row][col] != word[count])
            return false;
            
        visited[row][col] = true;    
        if( dfs(board, word, row-1, col, count+1, visited) || dfs(board, word, row+1, col, count+1, visited) ||
            dfs(board, word, row, col-1, count+1, visited) || dfs(board, word, row, col+1, count+1, visited))
            return true;
        else{
            visited[row][col] = false;
            return false;
        }
    }
};