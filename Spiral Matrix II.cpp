class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> >res(n,vector<int>(n,0));
        if(n==0) return res;
        work(res,0,0,n-1,n-1,1);
        return res;
    }
    void work(vector<vector<int> > &res,int x1,int y1,int x2,int y2,int n)
    {
        if(x1>x2 || y1>y2) return;
        for(int i=y1;i<=y2;i++)
        {
            res[x1][i] = n++;
        }
        for(int i=x1+1;i<=x2;i++)
        {
            res[i][y2] = n++;
        }
        if(x2>x1)
        {
            for(int i=y2-1;i>=y1;i--)
            {
                res[x2][i] = n++;
            }
        }
        if(y2>y1)
        {
            for(int i=x2-1;i>=x1+1;i--)
            {
                res[i][y1] = n++;
            }
        }
        work(res,x1+1,y1+1,x2-1,y2-1,n);
    }
};
