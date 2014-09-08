class Solution {
public:
    // 容积即面积，它受长和高的影响，当长度减小时候，高必须增长才有可能提升面积，所以我们从长度最长时开始递减，然后寻找更高的线来更新候补；
    int maxArea(vector<int> &height) {
        int ret = 0;
        int left = 0;
        int right = height.size() - 1;
        while(left < right){
            int minHeight = height[left] < height[right] ? height[left] : height[right];
            int area = minHeight * (right - left);
            ret = area > ret ? area : ret;
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        return ret;
    }
};