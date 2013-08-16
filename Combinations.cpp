class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> >res;
        vector<int> tmp;
        func(res,n,k,1,0,tmp);
        return res;
    }
    void func(vector<vector<int> > &res,int n, int k, int dep,int pre, vector<int> & tmp)
    {
        if(dep ==k+1) 
        {
            res.push_back(tmp);
            return;
        }
        for(int i=pre+1;i<=n;i++)
        {
            tmp.push_back(i);
            func(res,n,k,dep+1,i,tmp);
            tmp.pop_back();
        }
    }
};
