class Solution {
public:
    // CC150 
    void setZeroes(vector<vector<int> > &matrix) {
        bool first_row_zero = false;
        bool first_col_zero = false;
        
        int m = matrix.size();
        if(m == 0) return;
        int n = matrix[0].size();
        
        for(int i = 0; i < m; ++i) 
            if(matrix[i][0] == 0)
                first_col_zero = true;
                
        for(int j = 0; j < n; ++j)
            if(matrix[0][j] == 0)
                first_row_zero = true;
                
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(first_row_zero){
            for(int j = 0; j < n; ++j)
                matrix[0][j] = 0;
        }
        if(first_col_zero){
            for(int i = 0; i < m; ++i)
                matrix[i][0] = 0;
        }
    }
};