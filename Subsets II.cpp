//用哈希表来去重
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> >res;
        set<vector<int> >set;
        vector<int> tmp;
        sort(S.begin(),S.end());
        func(res,set,S,0,tmp);
        return res;
    }
    void func(vector<vector<int> > &res,set<vector<int> >&set,vector<int> &S,int index, vector<int> & tmp)
    {
        if(index ==S.size()) 
        {
            if(set.find(tmp)==set.end()) 
            {
                set.insert(tmp);
                res.push_back(tmp);
            }
            return;
        }

        tmp.push_back(S[index]);
        func(res,set,S,index+1,tmp);
        tmp.pop_back();
        func(res,set,S,index+1,tmp);
    }
};

//不用哈希表来去重
//对于连续的重复元素，仅第一次时使用，后面的去掉
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> >res;
        vector<int> tmp;
        sort(S.begin(),S.end());
        func(res,S,0,tmp,true);
        return res;
    }
    void func(vector<vector<int> > &res,vector<int> &S,int index, vector<int> & tmp,bool use)
    {
        if(index ==S.size()) 
        {
                res.push_back(tmp);
            return;
        }
        func(res,S,index+1,tmp,false);
        if(index>=1 && S[index] == S[index-1] && !use ) return;
        tmp.push_back(S[index]);
        func(res,S,index+1,tmp,true);
        tmp.pop_back();
        
    }
};
