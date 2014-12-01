class Solution {
public:
    // treat each level as a histogram
    int maximalRectangle(vector<vector<char> > &matrix) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        
        int max_rect = 0;
        vector<int> height(n, 0);
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(i == 0) 
                    height[j] = matrix[0][j] - '0';
                else{
                    height[j] = matrix[i][j] == '0' ? 0 : height[j]+1;
                }
            }
            max_rect = max(max_rect, maximalHistogram(height));
        }
        return max_rect;
    }
    
    int maximalHistogram(vector<int> height){
        if(height.size() == 0) return 0;
        
        stack<int> stk;
        int max_area = 0;
        int i = 0;
        height.push_back(0);
        while(i < height.size()){
            if(stk.empty() || height[i] >= height[stk.top()]){
                stk.push(i);
                i++;
            }
            else{
                int index = stk.top();
                stk.pop();
                int h = height[index];
                int w = stk.empty() ? i : i-1-stk.top();
                max_area = max(max_area, h*w);
            }
        }
        return max_area;
    }
};