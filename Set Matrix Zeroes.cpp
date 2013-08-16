class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool z1=false;
        bool z2=false;
        int m = matrix.size();
        if(m==0) return;
        int n = matrix[0].size();
        if(n==0) return;
        for(int i=0;i<m;i++)
        {
            if(matrix[i][0]==0)
            {
                z1=true;
                break;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(matrix[0][i]==0)
            {
                z2=true;
                break;
            }
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        for(int i=1;i<m;i++)
        {
            if(matrix[i][0]==0)
            {
                for(int j=1;j<n;j++)
                {
                    matrix[i][j]=0;
                }
            }
        }
        for(int i=1;i<n;i++)
        {
            if(matrix[0][i]==0)
            {
                 for(int j=1;j<m;j++)
                {
                    matrix[j][i]=0;
                }
            }
        }
        if(z1)
        {
            for(int j=0;j<m;j++)
            {
                matrix[j][0]=0;
            }
        }
        if(z2)
        {
            for(int j=0;j<n;j++)
            {
                matrix[0][j]=0;
            }
        }
    }
};
