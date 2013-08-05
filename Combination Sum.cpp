class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(candidates.begin(),candidates.end());
        vector<vector<int> > res;
        vector<int> a;
        combine(candidates,0,target,res,a);
        return res;
    }
    void combine(vector<int> &candidates, int index,int target, vector<vector<int> > &res, vector<int> &a)
    {
        if(target == 0)
        {
            vector<int> tmp(a);
            res.push_back(tmp);
            return;
        }
        if(index >= candidates.size() || target < candidates[index]) return;
        for(int i=index;i<candidates.size();i++)
        {
            a.push_back(candidates[i]);
            combine(candidates,i,target-candidates[i],res,a);
            a.pop_back();
        }
    }
};
