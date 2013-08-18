class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n= triangle.size();
        vector<int> dp(n,0);
        for(int i=n-1;i>=0;i--)
        {
            
            for(int j=0;j<=i;j++)
            {
                if(i==n-1) dp[j]=triangle[i][j];
                else
                {
                    dp[j] = min(dp[j],dp[j+1]) +triangle[i][j];
                }
            }
        }
        return dp[0];
    }
};
