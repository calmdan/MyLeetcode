//use dp[][]，二维
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = obstacleGrid.size();
        if(m==0) return 0;
        int n = obstacleGrid[0].size();
        vector<vector<int> > dp(m,vector<int>(n,0));
        if(obstacleGrid[m-1][n-1]==1) return 0;
        else dp[m-1][n-1] = 1;
        bool flag = false;
        for(int i=m-1;i>=0;i--)
        {
            if(obstacleGrid[i][n-1]==1)
            {
                flag = true;
            }
            if(flag) dp[i][n-1] =0;
            else dp[i][n-1] = 1;
        }
        for(int j=n-2;j>=0;j--)
        {
            if(obstacleGrid[m-1][j]==1) dp[m-1][j]=0;
            else dp[m-1][j] = dp[m-1][j+1];
        }
        for(int i=m-2;i>=0;i--)
        {
            for(int j=n-2;j>=0;j--)
            {
                if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else dp[i][j] = dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};

//use dp[],一维
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = obstacleGrid.size();
        if(m==0) return 0;
        int n = obstacleGrid[0].size();
        vector<int> dp(n+1,0);
        if(obstacleGrid[m-1][n-1]==1) return 0;
        else dp[n-1] = 1;
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(obstacleGrid[i][j]==1) dp[j]=0;
                else dp[j] +=dp[j+1];
            }
        }
        return dp[0];
    }
};
