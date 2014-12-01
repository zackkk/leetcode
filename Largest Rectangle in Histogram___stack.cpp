class Solution {
public:
    // stack
    // treat each rectangle as the shortest height in the rectangle, find its max length.
    // until found its left shorter, and right shorter, since they have their own rectangle, we can enumerate all cases in this way 
    // O(n^2) ---> time limit exceeded --->  optimize, save left shorter & right shorter
    // maintain a stack of index of increasing height, so the left shorter is the lower element is the stack, once we meet its right shorter
    // then we can get the area of that height.
    int largestRectangleArea(vector<int> &height) {
        int n = height.size();
        if(n == 0) return 0;
        stack<int> stk; // index
        
        int max_area = 0;
        height.push_back(0); // point, when stack is 1,2,3,4,5, use 0 to pop all.
        int i = 0;
        while(i <= n){
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