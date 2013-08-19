/*[Analysis]
方法一：暴力
对于每一个height[i]，从height[i]向两边找边界，复杂度为O(n^2)，过Large Judge会TLE。

方法二：动态规划
（1）用left[i]记录从height[i]往左，连续的大于等于height[i]的左边界，按照从0~n更新left[i]；
     对于j=height[i]，则更新left[i]=left[j]，否则停止对left[i]的更新，i++；
（2）用right[i]记录从height[i]往右，连续的大于等于height[i]的右边界，按照从n~0更新right[i]；
     对于j>i，如果height[j]>=height[i]，则更新right[i]=right[j]，否则停止对right[i]的更新，i++；*/
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int max = 0;
        int len = height.size();
        int left[len+1], right[len+1];
   
        for(int i = 0; i < len; ++i){
            left[i] = i;
            while(left[i] >= 1 && height[i] <= height[left[i]-1]){
                left[i] = left[left[i]-1];
            }
        }
        for(int i = len - 1; i >= 0; --i){
            right[i] = i;
            while(right[i] <= len-2 && height[i] <= height[right[i]+1]){
                right[i] = right[right[i]+1];
            }
        }
        for(int i = 0; i < len; ++i){
            // area
            int area = (right[i] - left[i] + 1) * height[i];
            max = max > area ? max : area;
        }
        return max;
    }
};
