//top down
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
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
            combine(candidates,i+1,target-candidates[i],res,a);//i+1!!!!!!!!!
            a.pop_back();
            while(i<candidates.size()-1 && candidates[i+1]==candidates[i]) i++;//!!!!!!!!!
        }
    }
};

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {  
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
        GetCombinations(candidates, sum, i+1, target, solution, result);  
        solution.pop_back();  
        sum-=candidates[i];      
        while(i<candidates.size()-1 && candidates[i+1]==candidates[i]) i++;
      }  
    }  
};

//用set去重
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

