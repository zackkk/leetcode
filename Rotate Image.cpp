class Solution {
public:
    // CC150
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for(int layer = 0; layer < n/2; ++layer){
            for(int i = layer; i < n-1-layer; ++i){
                int tmp = matrix[layer][i];
                matrix[layer][i] = matrix[n-1-i][layer];
                matrix[n-1-i][layer] = matrix[n-1-layer][n-1-i];
                matrix[n-1-layer][n-1-i] = matrix[i][n-1-layer];
                matrix[i][n-1-layer] = tmp;
            }
        }
    }
};