//左右斜线的处理
//两个数组，i+j,i-j+n-1
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > res;
        vector<bool> cc(n,true);
        vector<bool> cl(2*n-1,true);
        vector<bool> cr(2*n-1,true);
        vector<string> nq(n,string(n,'.'));
        solve(res,cc,cl,cr,0,nq,n);
        return res;
    }
    void solve(vector<vector<string> > &res, vector<bool> &cc,
               vector<bool> &cl, vector<bool> &cr,
               int dep, vector<string> &nq,int n)
    {
        if(dep==n)
        {
            res.push_back(nq);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(cc[i] && cr[dep+i] && cl[dep-i+n-1])
            {
                cc[i] = false;
                cr[dep+i] = false;
                cl[dep-i+n-1] = false;
                nq[dep][i]= 'Q';
                solve(res,cc,cl,cr,dep+1,nq,n);
                nq[dep][i]= '.';
                cc[i] = true;
                cr[dep+i] = true;
                cl[dep-i+n-1] = true;
            }
        }
        return;
    }
};
