class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> dp(n,INT_MIN);
        dp[0]=A[0];
        int max=dp[0];
        for(int i=1;i<n;i++)
        {
            if(dp[i-1]<0) dp[i]=A[i];
            else dp[i]=dp[i-1]+A[i];
            if(max<dp[i]) max = dp[i];
        }
        return max;
    }
};
