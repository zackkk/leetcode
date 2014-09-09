class Solution {
public:
    // treat each level as a histogram
    int maximalRectangle(vector<vector<char> > &matrix) {
        int m = matrix.size();
        if(m == 0) return 0;  // bug happened here
        int n = matrix[0].size();
        vector<vector<int>> height (m, vector<int> (n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                height[i][j] = matrix[i][j] - '0';
                if(i > 0)
                    height[i][j] = height[i][j] == 0 ? 0 : height[i-1][j] + 1;
            }
        }
        
        int maxArea = 0;
        for(int i = 0; i < m; i++){
            maxArea = max(maxArea, maxHistogram(height[i]));
        }
        return maxArea;
    }
    
    int maxHistogram(vector<int> &heights){
        heights.push_back(0);
        int maxArea = 0;
        int i = 0;
        stack<int> stk;
        while(i < heights.size()){
            if(stk.empty() || heights[i] >= heights[stk.top()]){
                stk.push(i);
                i++;
            }
            else{
                int cur = stk.top();
                stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1;
                int height = heights[cur];
                maxArea = max(maxArea, width * height);
            }
        }
        return maxArea;
    }
};