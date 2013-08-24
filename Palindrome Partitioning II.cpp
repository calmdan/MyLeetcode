class Solution {
public:
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        vector<vector<bool>> dp(len,vector<bool>(len,false));
        for(int i=0;i<len;i++)
        {
            dp[i][i]=true;
        }
        for(int i=len-2;i>=0;i--)
        {
            dp[i][i+1] = s[i]==s[i+1];
            for(int j=i+2;j<len;j++)
            {
                dp[i][j]= s[i]==s[j] && dp[i+1][j-1];
            }
        }
        vector<int> res(len+1,INT_MAX);
        res[len]=0;
        for(int i=len-1;i>=0;i--)
        {
            for(int j=i;j<len;j++)
            {
                if(dp[i][j])
                {
                    res[i] = min(res[i],res[j+1]+1);
                }
            }
        }
        return res[0]-1;
    }
};
