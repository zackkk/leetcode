class Solution {
public:

    void setZeroes(vector<vector<int> > &matrix) {
        int rowNum = matrix.size();
        int colNum = matrix[0].size();
        // use first row and first column as flags
        bool firstRowZero = false;
        bool firstColZero = false;
        for(int i = 0; i < rowNum; i++){
            if(matrix[i][0] == 0){
                firstColZero = true;
                break;
            }
        }
        for(int j = 0; j < colNum; j++){
            if(matrix[0][j] == 0){
                firstRowZero = true;
                break;
            }
        }
        
        // set flags
        for(int i = 1; i < rowNum; i++){
            for(int j = 1; j < colNum; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // set zeros
        for(int i = 1; i < rowNum; i++){
            for(int j = 1; j < colNum; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        if(firstRowZero){
            for(int j = 0; j < colNum; j++)
                matrix[0][j] = 0;
        }
        if(firstColZero){
            for(int i = 0; i < rowNum; i++){
                matrix[i][0] = 0;
            }
        }
            
    }
};