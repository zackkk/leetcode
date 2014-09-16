class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // check rows
        for(int i = 0; i < 9; i++){
            vector<int> a (10, 0);
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                a[board[i][j] - '0']++;
                if(a[board[i][j] - '0'] > 1) return false;
            }
        }
        
        // check columns
        for(int j = 0; j < 9; j++){
            vector<int> a (10, 0);
            for(int i = 0; i < 9; i++){
                if(board[i][j] == '.') continue;
                a[board[i][j] - '0']++;
                if(a[board[i][j] - '0'] > 1) return false;
            }
        }
        
        // check sub-boards
        for(int i = 0; i <= 6; i+=3){
            for(int j = 0; j <= 6; j +=3){
                vector<int> a (10, 0);
                for(int k = i; k < i+3; k++){
                    for(int l = j; l < j+3; l++){
                        if(board[k][l] == '.') continue;
                        a[board[k][l] - '0']++;
                        if(a[board[k][l] - '0'] > 1) return false;
                    }
                }
            }
        }
        
        return true;
    }
};