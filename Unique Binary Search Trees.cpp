class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> dp(n+1,0);
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                dp[i]+=dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
};

//卡特兰数，C(n+1)与C(n)的递推关系，http://en.wikipedia.org/wiki/Catalan_number
/ O(n) time, O(1) space
public int numTrees(int n) {
    int c = 1;
    for (int i = 2; i <= n; i++)
        c = 2*(2*i-1)*c/(i+1);
    return c;
}
