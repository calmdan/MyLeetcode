class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> dp(n,0);
        dp[n-1]=1;
        for(int i=0;i<m;i++)
        {
            for(int j=n-2;j>=0;j--)
            {
                dp[j] +=dp[j+1];
            }
        }
        return dp[0];
    }
};
