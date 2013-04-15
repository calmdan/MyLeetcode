class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<int,int> nums;
        vector<int> results;
        for(int i = 0; i<numbers.size(); i++)
        {
            if(nums.find(target - numbers[i]) != nums.end())
            {
                if(i+1 > nums[target - numbers[i]] )
                {
                    results.push_back(nums[target - numbers[i]]);
                    results.push_back(i+1);
                }
                else
                {
                    results.push_back(i+1);
                    results.push_back(nums[target - numbers[i]]);
                }
            }
            else
            {
                nums[numbers[i]]= i+1;
            }
        }
        return results;
    }
};
