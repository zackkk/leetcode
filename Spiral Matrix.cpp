class Solution {
public:
    // image rotate transformation ---> complex
    // consider add one element each time instead of one line
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ret;
        int m = matrix.size();
        if(m == 0) return ret;
        int n = matrix[0].size();
        vector<vector<bool>> visited (m, vector<bool> (n, false));
        int i = 0;
        int j = 0;
        int k = 1;
        ret.push_back(matrix[i][j]);
        visited[i][j] = true;
        while(k < m * n){
            // go to right
            while(j + 1 < n && !visited[i][j+1]){
                j++;
                k++;
                ret.push_back(matrix[i][j]);
                visited[i][j] = true;
            }
            
            // go to bottom
            while(i + 1 < m && !visited[i+1][j]){
                i++;
                k++;
                ret.push_back(matrix[i][j]);
                visited[i][j] = true;
            }
            
            // go to left
            while(j - 1 >= 0 && !visited[i][j-1]){
                j--;
                k++;
                ret.push_back(matrix[i][j]);
                visited[i][j] = true;
            }
            
            // go to top
            while(i - 1 >= 0 && !visited[i-1][j]){
                i--;
                k++;
                ret.push_back(matrix[i][j]);
                visited[i][j] = true;
            }
        }
        return ret;
    }
};