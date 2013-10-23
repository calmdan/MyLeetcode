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

//new
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        unordered_map<int,int> map;
        vector<int> res;
        for(int i=0;i<numbers.size();i++)
        {
            if(map.find(target-numbers[i]) !=map.end())
            {
                res.push_back(map[target-numbers[i]]);
                res.push_back(i+1);
                return res;
            }
            else map[numbers[i]]=i+1;
        }
    }
};
