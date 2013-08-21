//递归比较容易想到，会超时。
//然后想到DP，比较绕。子问题设计，dp[i,j]的含义，边界。
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int l= s1.length(),m = s2.length(),n=s3.length();
        if(n==0) return true;
        if(l+m!=n) return false;
        vector< vector<bool>> dp(l+2, vector<bool>(m+2, false));
        for(int i=0;i<l;i++)
        {
            if(s1[i]==s3[i]) dp[i+1][0]=true;
            else break;
        }
        for(int i=0;i<m;i++)
        {
            if(s2[i]==s3[i]) dp[0][i+1]=true;
            else break;
        }
        for(int i=0;i<=l;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(s1[i]==s3[i+j]) dp[i+1][j] = dp[i+1][j] || dp[i][j];
                if(s2[j]==s3[i+j]) dp[i][j+1] = dp[i][j+1] || dp[i][j];
            }
        }
        return dp[l][m];
    }
  
};
