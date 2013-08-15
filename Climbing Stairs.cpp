class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<=1) return 1;
        vector<int> dp(n+1,0);
        dp[0]=dp[1]=1;
        return f(n,dp);
    }
    int f(int n,vector<int> & dp)
    {
        if(dp[n]!=0) return dp[n];
        dp[n]=f(n-1,dp)+f(n-2,dp);
        return dp[n];
    }

};
