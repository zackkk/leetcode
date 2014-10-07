class Solution {
public:
    // stack
    // treat each rectangle as the shortest height in the rectangle, find its max length.
    // until found its left shorter, and right shorter, since they have their own rectangle, we can enumerate all cases in this way 
    // O(n^2) ---> time limit exceeded --->  optimize, save left shorter & right shorter
    // maintain a stack of index of increasing height, so the left shorter is the lower element is the stack, once we meet its right shorter
    // then we can get the area of that height.
    int largestRectangleArea(vector<int> &height) {
        height.push_back(0); // when all increasing in the stack, need to pop all elements at the end
        stack<int> stk; // store index for left shorter, we can get height through its index.
        int maxArea = 0;
        int i = 0;
        while(i < height.size()){ 
            if(stk.empty() || height[i] >= height[stk.top()]){
                stk.push(i);
                i++;
            }
            // find right shorter, then calculate area for this height
            else{ 
                int cur = stk.top();
                stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1; // when stack is empty, it means no left shorter, all others are taller.
                int area = height[cur] * width;
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};