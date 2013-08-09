class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string pp(p);
        int i=0;
        int notstarlength =0;
        while(i<pp.length())
        {
            if(pp[i]!='*') notstarlength++;
            if(pp[i]=='*' && (i+1)!=pp.length() && pp[i+1]=='*') pp.erase(i,1);
            else i++;
        }
        
        int len1 = pp.length();
        int len2 = strlen(s);
        if(len2 < notstarlength) return false;
        vector<vector<bool>> dp(2,vector<bool>(len2+1,false));
        int flag=1;
        dp[0][0]= true;
        for(int i=1;i<=len1;i++)
        {
            if(pp[i-1]=='*')
            {
                dp[flag][0]=dp[1-flag][0];
                int k;
                for(k=1;k<=len2;k++)
                {
                    if(dp[flag][k-1]==true || dp[1-flag][k]==true) break;
                    else dp[flag][k]=false;
                }
                for(;k<=len2;k++)
                {
                    dp[flag][k]=true;
                }
            }
            else
            {
                dp[flag][0]=false;
                for(int j=1;j<=len2;j++)
                {
                    dp[flag][j]= false;
                    if(pp[i-1]=='?' || pp[i-1]==s[j-1])
                    {
                        dp[flag][j]=dp[1-flag][j-1];
                    }
                }
            }
            flag= 1-flag;
        }
        return dp[1-flag][len2];
    }
};
