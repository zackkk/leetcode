class Solution {
public:
    // dfs
    bool exist(vector<vector<char> > &board, string word) {
        if(word.size() == 0) return true;
        int m = board.size();
        if(m == 0) return false;
        int n = board[0].size();
        vector<vector<bool>> visited (m, vector<bool> (n, false));
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(board[i][j] == word[0]){
                    
                    if(dfs(board, word, 0, i, j, visited))
                        return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>> &board, string word, int cur, int row, int col, vector<vector<bool>> &visited){
        if(cur == word.size()) return true;
        if(row < 0 || row >= board.size() || col < 0 || col > board[0].size()) return false;
        
        if(board[row][col] != word[cur]) return false;
        if(visited[row][col]) return false; // where bug happens
        
        visited[row][col] = true;
        if(dfs(board, word, cur+1, row+1, col, visited) ||
           dfs(board, word, cur+1, row-1, col, visited) ||
           dfs(board, word, cur+1, row, col+1, visited) ||
           dfs(board, word, cur+1, row, col-1, visited))
           return true;
        visited[row][col] = false;
        return false;
    }
};