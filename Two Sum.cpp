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
                    results.push_back(nums[target - numbers[i]]);
                    results.push_back(i+1);
            }
            else
            {
                nums[numbers[i]]= i+1;
            }
        }
        return results;
    }
};
