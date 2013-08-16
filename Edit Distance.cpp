class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = word1.length();
        int n = word2.length();
        if(m==0) return n;
        if(n==0) return m;
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return func(dp,m,n,0,0,word1,word2);
    }
    int func(vector<vector<int>> &dp, int m, int n, int i, int j,string &word1,string &word2)
    {
        if(i==m) 
        {
            dp[i][j]=n-j;
            return n-j;
        }
        if(j==n) 
        {
            dp[i][j]=m-i;
            return m-i;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(word1[i]==word2[j])
        {
            dp[i][j] = func(dp,m,n,i+1,j+1,word1,word2);
            return dp[i][j];
        }
        else
        {
            dp[i][j] = min(func(dp,m,n,i,j+1,word1,word2),func(dp,m,n,i+1,j,word1,word2));
            dp[i][j] = min(dp[i][j],func(dp,m,n,i+1,j+1,word1,word2));
            dp[i][j] ++;
            return dp[i][j];
        }
    }
};
