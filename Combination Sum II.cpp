class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(candidates.begin(),candidates.end());
        vector<vector<int> > res;
        set<vector<int>> r;
        vector<int> a;
        combine(candidates,0,target,r,a);
        for(auto i=r.begin();i!=r.end();i++)
        {
            res.push_back(*i);
        }
        return res;
    }
    void combine(vector<int> &candidates, int index,int target, set<vector<int> > &res, vector<int> &a)
    {
        if(target == 0)
        {
            vector<int> tmp(a);
            res.insert(tmp);
            return;
        }
        if(index >= candidates.size() || target < candidates[index]) return;
        for(int i=index;i<candidates.size();i++)
        {
            a.push_back(candidates[i]);
            combine(candidates,i+1,target-candidates[i],res,a);
            a.pop_back();
        }
    }
};
