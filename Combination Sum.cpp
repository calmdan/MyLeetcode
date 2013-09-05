//top down
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
    void combine(vector<int> &candidates, int index,int target, vector<vector<int> > &res, vector<int> a)
    {
        if(target == 0)
        {
            res.push_back(a);
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

//bottom up
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {  
      // Start typing your C/C++ solution below  
      // DO NOT write int main() function  
      vector<vector<int> > result;  
      vector<int> solution;  
      int sum=0;  
      std::sort(candidates.begin(), candidates.end());  
      GetCombinations(candidates,sum, 0, target, solution, result);  
      return result;  
    }  
    void GetCombinations(  
      vector<int>& candidates,  
      int& sum,  
      int level,  
      int target,  
      vector<int>& solution,  
      vector<vector<int> >& result)  
    {  
      if(sum > target) return;  
      if(sum == target)  
      {  
        result.push_back(solution);  
        return;  
      }  
      for(int i =level; i< candidates.size(); i++)  
      {  
        sum+=candidates[i];  
        solution.push_back(candidates[i]);  
        GetCombinations(candidates, sum, i, target, solution, result);  
        solution.pop_back();  
        sum-=candidates[i];        
      }  
    }  
};
