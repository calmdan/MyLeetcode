class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = 0;
        int r = height.size()-1;
        int result = 0;
        while(l<r)
        {
            int water = min(height[l],height[r])*(r-l);
            if(result <water) result = water;
            if(height[l] < height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return result;
    }
    
};
