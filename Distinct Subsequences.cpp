class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = S.length();
        int n = T.length();
        if(n==0) return 1;
        if(n>m) return 0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        for(int i=0;i<=m;i++)
        {
            dp[i][0]=1;
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j] = dp[i-1][j]+(S[i-1]==T[j-1]?dp[i-1][j-1]:0);
            }
        }
        return dp[m][n];
    }
};

//每次只用到上一行的数据，可以只用一维的dp数组
class Solution {
public:
    int numDistinct(string S, string T) {
        vector<int> f(T.size()+1);
        f[T.size()] = 1;
        for (int i = S.size()-1; i >= 0; --i) {
            for (int j = 0; j < T.size(); ++j) {
                f[j] += (S[i]==T[j])*f[j+1];
            }
        }
        return f[0];
    }
};
