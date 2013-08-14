class Solution {
public:
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int res=0;
        vector<bool> cc(n,true);
        vector<bool> cl(2*n-1,true);
        vector<bool> cr(2*n-1,true);

        solve(res,cc,cl,cr,0,n);
        return res;
    }
    void solve(int &res, vector<bool> &cc,
               vector<bool> &cl, vector<bool> &cr,
               int dep,int n)
    {
        if(dep==n)
        {
            res++;
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(cc[i] && cr[dep+i] && cl[dep-i+n-1])
            {
                cc[i] = false;
                cr[dep+i] = false;
                cl[dep-i+n-1] = false;
                solve(res,cc,cl,cr,dep+1,n);
                cc[i] = true;
                cr[dep+i] = true;
                cl[dep-i+n-1] = true;
            }
        }
        return;

    }
};
