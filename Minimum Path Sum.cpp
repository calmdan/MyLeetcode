class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int> > dp(m,vector<int>(n,INT_MAX));
        for(int i =n-1;i>=0;i--)
        {
            if(i==n-1) dp[m-1][i] = grid[m-1][i];
            else dp[m-1][i] = grid[m-1][i]+ dp[m-1][i+1];
        }
         for(int i =m-1;i>=0;i--)
        {
            if(i==m-1) dp[i][n-1] = grid[i][n-1];
            else dp[i][n-1] = grid[i][n-1]+ dp[i+1][n-1];
        }
        for(int i=m-2;i>=0;i--)
        {
            for(int j=n-2;j>=0;j--)
            {
                dp[i][j] = min(dp[i+1][j],dp[i][j+1])+grid[i][j];
            }
        }
        return dp[0][0];
    }
};



class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();

        vector<int> dp(n + 1, INT_MAX);
        dp[1] = 0;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                dp[j + 1] = min(dp[j + 1], dp[j]) + grid[i][j];

        return dp.back();
    }
};
