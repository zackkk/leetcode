class Solution {
public:
    // two pointers
    // area = min(height[i], height[j]) * (j - i)
    // when i = 0 && j = height.size()-1, (j - i) decreased, then we want to increase min(height[i], height[j]) to increase the area.
    // algo correctness proof: http://tianrunhe.wordpress.com/2012/07/13/container-with-most-water/
    int maxArea(vector<int> &height) {
        int ret = 0;
        int left = 0;
        int right = height.size() - 1;
        while(left < right){
            int area = (right - left) * min(height[left], height[right]);
            ret = max(ret, area);
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        return ret;
    }
};