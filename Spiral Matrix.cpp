class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        int m=matrix.size();
        if(m==0) return res;
        int n=matrix[0].size();
        work(matrix,0,0,m-1,n-1,res);
        return res;
    }
    void work(vector<vector<int> > &matrix,int x1,int y1,int x2,int y2,vector<int> &res)
    {
        if(x1>x2 || y1>y2) return;
        for(int i=y1;i<=y2;i++)
        {
            res.push_back(matrix[x1][i]);
        }
        for(int i=x1+1;i<=x2;i++)
        {
            res.push_back(matrix[i][y2]);
        }
        if(x2>x1)
        {
            for(int i=y2-1;i>=y1;i--)
            {
                res.push_back(matrix[x2][i]);
            }
        }
        if(y2>y1)
        {
            for(int i=x2-1;i>=x1+1;i--)
            {
                res.push_back(matrix[i][y1]);
            }
        }
        work(matrix,x1+1,y1+1,x2-1,y2-1,res);
    }
};
