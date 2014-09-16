class Solution {
public:
    // image rotate transformation ---> complex
    // build the matrix -> fill blanks
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> ret_empty;
        if(n == 0) return ret_empty;
        vector<vector<int>> ret (n, vector<int> (n, 0)); // use itself as bool "visited"
        int i = 0;
        int j = 0;
        int k = 1;
        ret[0][0] = k++;
        while(k <= n*n){
            // go to right
            while(j + 1 < n && ret[i][j+1] == 0){
                j++;
                ret[i][j] = k++;
            }
            
            // go to bottom
            while(i + 1 < n && ret[i+1][j] == 0){
                i++;
                ret[i][j] = k++;
            }
            
            // go to left
            while(j - 1 >= 0 && ret[i][j-1] == 0){
                j--;
                ret[i][j] = k++;
            }
            
            // go to top
            while(i - 1 >= 0 && ret[i-1][j] == 0){
                i--;
                ret[i][j] = k++;
            }
        }
        return ret;
    }
};