class Solution {
public:
    // CC150
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for(int layer = 0; layer < n/2; layer++){
            for(int i = layer; i <= n-2-layer; i++){
                
                int top = matrix[layer][i];
                int left = matrix[n-1-i][layer];
                int bottom = matrix[n-1-layer][n-1-i];
                int right = matrix[i][n-1-layer];
                
                int tmp = top;
                // left -> top
                matrix[layer][i] = left; 
                matrix[n-1-i][layer] = bottom;
                matrix[n-1-layer][n-1-i] = right;
                matrix[i][n-1-layer] = tmp;
            }
        }
    }
};